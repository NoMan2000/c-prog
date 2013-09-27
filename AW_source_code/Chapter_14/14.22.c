Figure 14.22  Function search
/*
 *  Searches a list for a specified target value.  Returns a pointer to
 *  the first node containing target if found.  Otherwise returns NULL.
 */
list_node_t *
search(list_node_t *headp,  /* input - pointer to head of list  */
       int          target) /* input - value to search for      */
{
      list_node_t *cur_nodep; /* pointer to node currently being checked */

      for  (cur_nodep = headp;
            cur_nodep != NULL  &&  cur_nodep->digit != target;
            cur_nodep = cur_nodep->restp) {}

      return (cur_nodep);
}