Figure 14.36  Function delete Using Recursive Helper Function
/*
 *  Deletes first node containing the target key from an ordered list.
 *  Returns 1 if target found and deleted, 0 otherwise.
 */
int
delete(ordered_list_t *listp,  /* input/output - ordered list   */
       int             target) /* input - key of node to delete */
{
      int is_deleted;

      listp->headp = delete_ordered_node(listp->headp, target,
                                            &is_deleted);
      if (is_deleted)
            --(listp->size);

      return (is_deleted);
}
