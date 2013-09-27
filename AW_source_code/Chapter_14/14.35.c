Figure 14.35  Iterative Function delete
/*
 *  Deletes first node containing the target key from an ordered list.
 *  Returns 1 if target found and deleted, 0 otherwise.
 */
int
delete(ordered_list_t *listp,     /* input/output - ordered list   */
       int           target)      /* input - key of node to delete */
{
    list_node_t *to_freep,        /* pointer to node to delete               	 */
                *cur_nodep;       /* pointer used to traverse list until it
points to node preceding node to delete 	*/
    int         is_deleted;

    /*  If list is empty, deletion is impossible                         */
    if (listp->size == 0) {
         is_deleted = 0;

    /*  If target is in first node, delete it                            */
    } else if (listp->headp->key == target) {
         to_freep = listp->headp;
         listp->headp = to_freep->restp;
         free(to_freep);
         --(listp->size);
         is_deleted = 1;

    /*  Otherwise, look for node before target node; delete target       */
    } else {
         for  (cur_nodep = listp->headp;
               cur_nodep->restp != NULL  &&  cur_nodep->restp->key < target;
               cur_nodep = cur_nodep->restp) {}
         if (cur_nodep->restp != NULL  &&  cur_nodep->restp->key == target) {
             to_freep = cur_nodep->restp;
             cur_nodep->restp = to_freep->restp;
             free(to_freep);
             --(listp->size);
             is_deleted = 1;
         } else {
             is_deleted = 0;
         }
    }

    return (is_deleted);
}