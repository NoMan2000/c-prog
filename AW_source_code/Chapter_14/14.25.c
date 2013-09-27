Figure 14.25  Stack Manipulation with Functions push and pop
/*
 *  Creates and manipulates a stack of characters
 */

#include <stdio.h>
#include <stdlib.h>

/*  Include typedefs from Fig. 14.22 */
void push(stack_t *sp, stack_element_t c);
stack_element_t pop(stack_t *sp);

int
main(void)
{
      stack_t s = {NULL};  /* stack of characters - initially empty */
 
      /*  Builds first stack of Fig. 14.21        */
      push(&s, '2');
      push(&s, '+');
      push(&s, 'C');
 
      /*  Completes second stack of Fig. 14.21    */
      push(&s, '/');
 
      /*  Empties stack element by element        */
      printf("\nEmptying stack: \n");
      while (s.topp != NULL) {
            printf("%c\n", pop(&s));
      }
 
      return (0);
}
 
/*
 *  The value in c is placed on top of the stack accessed through sp
 *  Pre:  the stack is defined
 */
void
push(stack_t        *sp, /* input/output - stack          */
     stack_element_t c)  /* input        - element to add */
{
      stack_node_t *newp;  /* pointer to new stack node */
 
      /*  Creates and defines new node                  */
      newp = (stack_node_t *)malloc(sizeof (stack_node_t));
      newp->element = c;
      newp->restp = sp->topp;
 
      /*  Sets stack pointer to point to new node       */
      sp->topp = newp;
}
 
/*
 *  Removes and frees top node of stack, returning character value
 *  stored there.
 *  Pre:  the stack is not empty
 */
stack_element_t
pop(stack_t *sp) /* input/output - stack */
{
      stack_node_t    *to_freep;  /* pointer to node removed */
      stack_element_t  ans;       /* value at top of stack   */
 
      to_freep = sp->topp;           /*  saves pointer to node being deleted	*/
      ans = to_freep->element;       /* retrieves value to return 	*/
      sp->topp = to_freep->restp;    /* deletes top node 	*/
      free(to_freep);                /* deallocates space 	*/
 
      return (ans);
}
 
Emptying stack:
/
C
+
2