Figure 14.20  Recursive Function get_list
#include <stdlib.h>  /*  gives access to malloc */
#define SENT -1
/*
 *  Forms a linked list of an input list of integers 
 *  terminated by SENT
 */
list_node_t *
get_list(void)
{
      int data;
      list_node_t *ansp;

      scanf("%d", &data);
      if (data == SENT) {
            ansp = NULL;
      } else {
            ansp = (list_node_t *)malloc(sizeof (list_node_t));
            ansp->digit = data;
            ansp->restp = get_list();
      }

      return (ansp);
}