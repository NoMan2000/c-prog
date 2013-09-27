Figure 14.37  Recursive Helper Function delete_ordered_node
/*
 *  If possible, deletes node containing target key from list whose first
 *  node is pointed to by listp, returning pointer to modified list and 
 *  freeing deleted node.  Sets output parameter flag to indicate whether or 
 *  not deletion occurred.
 */
list_node_t *
delete_ordered_node(list_node_t *listp,      /* input/output - list to 
modify	*/
                    int          target,     /* input - key of node to 
delete       	*/
                    int         *is_deletedp)/* output - flag indicating whether or not target node found and deleted 	*/
{
      list_node_t *to_freep, *ansp;

      /* if list is empty - can't find target node       - simple case 1  	*/
      if (listp == NULL) {
            *is_deletedp = 0;
            ansp = NULL;

      /* if first node is the target, delete it          - simple case 2 	 */
      } else if (listp->key == target) {
            *is_deletedp = 1;
            to_freep = listp;
            ansp = listp->restp;
            free(to_freep);

      /* if past the target value, give up               - simple case 3  	*/
      } else if (listp->key > target) {
            *is_deletedp = 0;
            ansp = listp;

      /* in case target node is farther down the list,   - recursive step
         have recursive call modify rest of list and then return list    	 */
      } else {
            ansp = listp;
            ansp->restp = delete_ordered_node(listp->restp, target, 
is_deletedp);
      }

      return (ansp);
}
