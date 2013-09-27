Figure 14.34  Function insert and Recursive Function insert_in_order
/*
 *  Inserts a new node containing new_key in order in old_list, returning as
 *  the function value a pointer to the first node of the new list
 */
list_node_t *
insert_in_order(list_node_t *old_listp,  /* input/output */
                int          new_key)    /* input        */
{
      list_node_t *new_listp;
 
      if (old_listp == NULL) {
            new_listp = (list_node_t *)malloc(sizeof (list_node_t));
            new_listp->key = new_key;
            new_listp->restp = NULL;
      } else if (old_listp->key >= new_key) {
            new_listp = (list_node_t *)malloc(sizeof (list_node_t));
            new_listp->key = new_key;
            new_listp->restp = old_listp;
      } else {
            new_listp = old_listp;
            new_listp->restp = insert_in_order(old_listp->restp, new_key);
      }
 
      return (new_listp);
}
 
/*
 *  Inserts a node in an ordered list.
 */
void
insert(ordered_list_t *listp, /* input/output - ordered list */
       int             key)   /* input */
{
      ++(listp->size);
      listp->headp = insert_in_order(listp->headp, key);
}
