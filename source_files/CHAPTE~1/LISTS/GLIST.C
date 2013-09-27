/*****************************************************************************
 *
 *	glist.c (Generic List)
 *
 *	Generic (doubly-linked) List library functions
 *
 *	(c) Mark Virtue, 2001
 *
 *****************************************************************************
 */
#include <stdlib.h>
#include <mem.h>
#include "glist.h"

/*********************************************************************
 *
 *	STATIC (PRIVATE) ROUTINES
 *
 ********************************************************************/

/*
 *	An example of a compare function - used if a list's compare function is NULL
 *	Note: data1 and/or data2 can be NULL (NULL is considered "less than" anything else)
 *	Simply uses memcmp()
 */
static generic_cmp_func(void *data1, void *data2, int size)
{
	if (data1 == NULL || data2 == NULL)
		return (int)data1 - (int)data2;
	return memcmp(data1, data2, size);
}

/*
 *  Add the given size to the size and count fields of a list
 */
add_sizes(glist_t *list, int size)
{
    list->l_count++;
	list->l_size += size;
	list->l_total_size += size + sizeof(gnode_t);
}

/*
 *  Remove the given size from the size and count fields of a list
 */
subtract_sizes(glist_t *list, int size)
{
    list->l_count--;
	list->l_size -= size;
	list->l_total_size -= size + sizeof(gnode_t);
}

/*
 *	Free all the structures of a list
 *	Note: Recursive!
 */
static void _clear_list(glist_t *list, gnode_t *node)
{
	if (node == NULL)
		return;

	_clear_list(list, node->n_next);
	
	/*
	 *	Only free the data pointer if we allocated it in the first place
	 */
	if (list->l_flags & LIST_FLAG_COPY)
		free(node->n_data);
	free(node);
}

/*
 *	Perform the actual insertion of a node
 */
static void insert_this_node(glist_t *list, gnode_t *node)
{
	register gnode_t	*ptr;
	
	/*
	 *	If the list is empty, this task is trivial
	 */
	if (list->l_count == 0)
	{
		list->l_head = node;
		list->l_tail = node;
		node->n_next = NULL;
		node->n_prev = NULL;
        add_sizes(list, node->n_size);
		return;
	}

	/*
	 *	Check if we need to insert in sorted order
	 */
	if ((list->l_flags & LIST_FLAG_SORT) == 0)
		ptr = NULL;			/* it will go on the end */
	else					/* else find the spot */
	{
		for (ptr = list->l_head; ptr != NULL; ptr = ptr->n_next)
			if (list->l_cmpfunc(ptr->n_data, node->n_data, node->n_size) > 0)
				break;
	}

    add_sizes(list, node->n_size);

    /*
     *  Adjust the pointers accordingly
     */
	if (ptr == NULL)
	{
		/*
		 *	adding to END of list
		 */
		node->n_next = NULL;
		node->n_prev = list->l_tail;
		list->l_tail->n_next = node;
		list->l_tail = node;
		return;
	}
	
	/*
	 *	Otherwise, we've found spot for it - add new node BEFORE ptr
	 */
	node->n_next = ptr;
	node->n_prev = ptr->n_prev;
	if (ptr->n_prev == NULL)		/* ptr is FIRST node */
		list->l_head = node;
	else
		ptr->n_prev->n_next = node;
	ptr->n_prev = node;
}

/*
 *	Perform the actual deletion of a node
 *	Note: Sets the current index to GLIST_ERR
 */
static void delete_this_node(glist_t *list, gnode_t *node)
{
    int     size = node->n_size;

	if (node->n_next == NULL)
		list->l_tail = node->n_prev;
	else
		node->n_next->n_prev = node->n_prev;

	if (node->n_prev == NULL)
		list->l_head = node->n_next;
	else
		node->n_prev->n_next = node->n_next;

	if (list->l_flags & LIST_FLAG_COPY)
		free(node->n_data);
	free(node);

	subtract_sizes(list, size);
	list->l_curr_index = GLIST_ERR;
}


/*********************************************************************
 *
 *	GLOBAL ROUTINES
 *
 ********************************************************************/

/************************
 *
 * List operations
 *
 ***********************/

/*
 *	Create (malloc) a new list
 *	The flags will be stored in the list, as will the compare function
 *	If the compare function is NULL, use the generic one (above)
 *	The compare function can be changed later, using list_set_cmp_func()
 *	Returns the list, or NULL if malloc failed
 */
glist_t *list_create(int flags, glist_cmp_func_ptr func)
{
	glist_t	*list = malloc(sizeof *list);

	if (list != NULL)
	{
		list->l_count = 0;
		list->l_size = 0;
		list->l_total_size = sizeof *list;
		list->l_flags = flags;
		list->l_cmpfunc = func == NULL ? generic_cmp_func : func;
		list->l_head = NULL;
		list->l_tail = NULL;
		list->l_curr_index = GLIST_ERR;
	}

	return list;
}

/*
 *	Add a new node to the list
 *	Note: space for the data will be malloc'd if the list was created
 *	with the COPY flag turned on.
 *	Otherwise, the data pointer is simply used and "size" is ignored
 *	Returns GLIST_ERR if the list was NULL or a malloc failed
 */
list_add(glist_t *list, void *data, int size)
{
	gnode_t		*node;

	if (list == NULL)
		return GLIST_ERR;

	/*
	 *	Create space for the node itself
	 */
	if ((node = malloc(sizeof *node)) == NULL)
		return GLIST_ERR;

	if (list->l_flags & LIST_FLAG_COPY)
	{
		if (size != 0 && data != NULL)
		{	
			if ((node->n_data = malloc(size)) == NULL)
			{
				free(node);
				return GLIST_ERR;
			}
			(void)memcpy(node->n_data, data, size);
		}
	}
	else
		node->n_data = data;

	node->n_size = size;


	/*
	 *	Insert the new node in the list
	 */
	insert_this_node(list, node);
	return GLIST_OK;
}

/*
 *	Return the number of elements in the list, or GLIST_ERR if "list" is NULL
 */
list_count(glist_t *list)
{
	return list == NULL ? GLIST_ERR : list->l_count;
}

/*
 *	Return the total number of bytes of the data pointers of the nodes of the list,
 *	or GLIST_ERR if "list" is NULL
 */
list_size(glist_t *list)
{
	return list == NULL ? GLIST_ERR : list->l_size;
}

/*
 *	Return the total number of bytes of the list (including the node and list structures),
 *	or GLIST_ERR if "list" is NULL
 */
list_total_size(glist_t *list)
{
	return list == NULL ? GLIST_ERR : list->l_total_size;
}

/*
 *	Return the current index (0..n-1) of the list, or GLIST_ERR if "list" is NULL
 */
list_curr_index(glist_t *list)
{
	return list == NULL ? GLIST_ERR : list->l_curr_index;
}

/*
 *	Change the compare function of the list to func (can be NULL)
 */
void list_set_cmp_func(glist_t *list, glist_cmp_func_ptr func)
{
	list->l_cmpfunc = func;
}

/*
 *	Free up everything - empty a list - the "list" structure itself remains valid
 *	"list" can be NULL
 */
void list_empty(glist_t *list)
{
	if (list == NULL)
		return;

	_clear_list(list, list->l_head);
	list->l_count = 0;
}

/*
 *	Free up everything - destroy a list - the "list" structure is also destroyed
 *	"list" can be NULL
 */
void list_destroy(glist_t *list)
{
	if (list == NULL)
		return;

	list_empty(list);
	free(list);
}

/*
 *	Duplicate a list exactly.  Returns NULL if there were any problems
 *	"list" can be NULL
 */
glist_t *list_copy(glist_t *list1)
{
	glist_t				*list2;
	register gnode_t	*node;

	if (list1 == NULL)
		return NULL;

	if ((list2 = list_create(list1->l_flags, list1->l_cmpfunc)) != NULL)
		for (node = list1->l_head; node != NULL; node = node->n_next)
			if (list_add(list2, node->n_data, node->n_size) == GLIST_ERR)
			{
				list_destroy(list2);		/* rewind */
				return NULL;
			}

	return list2;
}

/*
 *	Perform an operation ("do_func") on every element in a list (traverse the list)
 *	Sets the "index" as it goes
 *	It will stop if "do_func" returns GLIST_ERR
 *	Returns the number of elements processed (including the last one if there was an error)
 */
list_do(glist_t *list, glist_func_ptr do_func)
{
	int					count = 0;
	register gnode_t	*node;

	if (list == NULL)
		return GLIST_ERR;

	for (node = list->l_head; node != NULL; node = node->n_next)
	{
		list->l_curr_index = count++;
		if (do_func != NULL && do_func(node->n_data) == GLIST_ERR)
			break;
	}
	return count;
}

/************************
 *
 *	Node operations based on the "index"
 *
 ***********************/

/*
 *	Retrieve a node's data pointer given the node's index in the list
 *	Sets the list's index as a side effect
 *	Returns NULL if the list or the index were invalid
 */
void *list_index_get(glist_t *list, int index)
{
	register gnode_t	*node;
	register int		i;

	if (list == NULL || index >= list->l_count)
		return NULL;

	node = list->l_head;
	for (i = 0; i < index; i++)
		node = node->n_next;
	list->l_curr_index = index;
	return node->n_data;
}

/*
 *	Run the given function ("do_func") on a node's data pointer given the node's index in the list
 *	Sets the list's index as a side effect
 *	Returns GLIST_OK if "do_func" was NULL, or else returns the return value of "do_func"
 */
list_index_do(glist_t *list, int index, glist_func_ptr do_func)
{
	register gnode_t	*node;
	register int		i;

	if (list == NULL || index >= list->l_count)
		return GLIST_ERR;

	node = list->l_head;
	for (i = 0; i < index; i++)
		node = node->n_next;

	list->l_curr_index = index;
	return do_func == NULL ? GLIST_OK : do_func(node->n_data);
}

/*
 *	Delete a node given the node's index in the list
 *	Sets the list's index as a side effect
 *	Returns GLIST_ERR if the list or the index were invalid, otherwise GLIST_OK
 */
list_index_delete(glist_t *list, int index)
{
	register gnode_t	*node;
	register int		i;
	
	if (list == NULL || index >= list->l_count)
		return GLIST_ERR;

	node = list->l_head;
	for (i = 0; i < index; i++)
		node = node->n_next;

	delete_this_node(list, node);
	return GLIST_OK;
}

/************************
 *
 *	Node operations based on the data in the node
 *
 ***********************/

/*
 *	Retrieve a node's data pointer given a data pointer that should match the node's data
 *	Gets the FIRST matching one
 *	Sets the list's index as a side effect
 *	Returns NULL if the list was invalid or if nothing matched
 */
void *list_data_get(glist_t *list, void *data)
{
	register gnode_t	*node;
	register int		i = 0;

	if (list == NULL)
		return NULL;
	
	for (node = list->l_head; node != NULL; node = node->n_next)
	{
		list->l_curr_index = i++;
		if (list->l_cmpfunc(node->n_data, data, node->n_size) == 0)
			return node->n_data;
	}
	list->l_curr_index = GLIST_ERR;
	return NULL;
}

/*
 *	Perform an operation ("do_func") on every element in a list that matches "data"
 *	Sets the "index" as it goes
 *	It will stop if "do_func" returns GLIST_ERR
 *	Returns the number of elements processed (including the last one if there was an error)
 */
list_data_do(glist_t *list, void *data, glist_func_ptr do_func)
{
	int					count = 0;
	register gnode_t	*node;
	register int		i = 0;

	if (list == NULL)
		return GLIST_ERR;

	for (node = list->l_head; node != NULL; node = node->n_next)
	{
		if (list->l_cmpfunc(node->n_data, data, node->n_size) == 0)
		{
			list->l_curr_index = i;
			count++;
			if (do_func != NULL && do_func(node->n_data) == GLIST_ERR)
				break;
		}
		i++;
	}
	return count;
}

/*
 *	Delete every element in a list that matches "data"
 *	Returns the number of elements deleted, or GLIST_ERR if list is NULL
 */
list_data_delete(glist_t *list, void *data)
{
	int					count = 0;
	register gnode_t	*node;

	if (list == NULL)
		return GLIST_ERR;

	for (node = list->l_head; node != NULL; node = node->n_next)
		if (list->l_cmpfunc(node->n_data, data, node->n_size) == 0)
		{
			delete_this_node(list, node);
			count++;
		}
	return count;
}

/*
 *	Returns the number of elements in the list whose data matches "data",
 *	or GLIST_ERR if list is NULL
 */
list_data_count(glist_t *list, void *data)
{
	return list_data_do(list, data, NULL);
}
