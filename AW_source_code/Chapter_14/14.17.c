Figure 14.17  Function print_list
/*
 *  Displays the list pointed to by headp
 */
void
print_list(list_node_t *headp)
{
      if (headp == NULL) {    /* simple case - an empty list 	*/
            printf("\n");
      } else {                /* recursive step - handles first element	*/
            printf("%d", headp->digit);  /*       leaves rest to 	*/
            print_list(headp->restp);    /*       recursion 	*/
      }
}