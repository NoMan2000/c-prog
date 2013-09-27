Figure 14.18  Comparison of Recursive and Iterative List Printing
                     /* Displays the list pointed to by headp */
                     void
                     print_list(list_node_t *headp)
{                                        { list_node_t *cur_nodep;
 if (headp == NULL) {/* simple case */
     printf("\n");                         for  (cur_nodep = headp; /* start at
 } else {         /* recursive step */                               beginning	*/
     printf("%d", headp->digit);                 cur_nodep != NULL; /* not at
     print_list(headp->restp);                                      end yet 	*/
 }                                               cur_nodep = cur_nodep->restp)
}                                             printf("%d", cur_nodep->digit);
                                           printf("\n");
                                         }