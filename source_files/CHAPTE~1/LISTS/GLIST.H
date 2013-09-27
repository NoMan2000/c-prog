/*****************************************************************************
 *
 *	glist.h (Generic List)
 *
 *	Header file for the Generic (doubly-linked) List library functions
 *
 *	(c) Mark Virtue, 2001
 *
 *****************************************************************************
 */
#ifndef _GLIST_H		/* ensure this file is only included once */
#define _GLIST_H

/*
 *	Some simple, useful #define's
 */
#ifndef TRUE
#define TRUE	1
#define FALSE	0
#endif

#ifndef NULL
#define NULL	((void *)0)
#endif

/*
 *	Some functions will return OK or ERR
 */
#define GLIST_ERR	-1
#define GLIST_OK	0

/*
 *	Some boolean flags for use with glist_t.l_flags
 */
#define LIST_FLAG_COPY	0x01	/* allocate space and copy passed-in data, or use existing data */
#define LIST_FLAG_SORT	0x02	/* insert data in list SORTED, using cmp func */

/*
 *	Some handy function pointer typedefs
 *
 *	First, for processing each element in a list:
 *	"data" is the data pointer from each node
 *	Should return GLIST_OK or GLIST_ERR
 */
typedef int				glist_func(void *data);
typedef glist_func		*glist_func_ptr;
/*
 *	Next, for comparing two elements in a list:
 *	"data1" and "data2" are two nodes' data pointers
 *	Should return <0, 0 or >0 (just like memcmp or strcmp)
 */
typedef int				glist_cmp_func(void *data1, void *data2, int size);
typedef glist_cmp_func	*glist_cmp_func_ptr;

/*
 *	The structure of each node in the list
 */
typedef struct gnode
{
	void			*n_data;		/* the data of the node (can be NULL if required) */
	int				n_size;			/* size, in bytes */
	struct gnode	*n_next;		/* next node, or NULL if this is last */
	struct gnode	*n_prev;		/* last node, or NULL if this is first */
}
	gnode_t;

typedef struct glist
{
	int					l_count;		/* how many elements in the list */
	int					l_size;			/* number of bytes of all data pointers of all nodes in the list */
	int					l_total_size;	/* TOTAL number of bytes in the list (including the list and node structures) */
	int					l_flags;		/* a collection of booleans (see above) */
	glist_cmp_func_ptr	l_cmpfunc;		/* compare function. If NULL then use an internal generic one */
	int					l_curr_index;	/* Treat the list like an array - 0..n-1 (or GLIST_ERR), when using search operations */
	struct gnode		*l_head;		/* first node, or NULL if none */
	struct gnode		*l_tail;		/* last node, or NULL if none */
}
	glist_t;

/*
 *	Prototypes for all the public functions in glist.c
 */
extern glist_t	*list_create(int flags, glist_cmp_func_ptr func);
extern int		list_add(glist_t *list, void *data, int size);
extern int		list_count(glist_t *list);
extern int		list_size(glist_t *list);
extern int		list_total_size(glist_t *list);
extern int		list_curr_index(glist_t *list);
extern void		list_set_cmp_func(glist_t *list, glist_cmp_func_ptr func);
extern void		list_empty(glist_t *list);
extern void		list_destroy(glist_t *list);
extern glist_t	*list_copy(glist_t *list1);
extern int		list_do(glist_t *list, glist_func_ptr do_func);
extern void		*list_index_get(glist_t *list, int index);
extern int		list_index_do(glist_t *list, int index, glist_func_ptr do_func);
extern int		list_index_delete(glist_t *list, int index);
extern void		*list_data_get(glist_t *list, void *data);
extern int		list_data_do(glist_t *list, void *data, glist_func_ptr do_func);
extern int		list_data_delete(glist_t *list, void *data);
extern int		list_data_count(glist_t *list, void *data);

#endif
