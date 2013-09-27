Figure 14.26  Creating and Maintaining a Queue
/*
 *  Creates and manipulates a queue of passengers.
 */

#include <stdio.h>

int scan_passenger(queue_element_t *passp);
void print_passenger(queue_element_t pass);
void add_to_q(queue_t *qp, queue_element_t ele);
queue_element_t remove_from_q(queue_t *qp);
void display_q(queue_t q);
 
int
main(void)
{
      queue_t pass_q = {NULL, NULL, 0}; /* passenger queue - initialized to
                                           empty state */
      queue_element_t next_pass, fst_pass;
      char choice;  /* user's request */
 
      /*  Processes requests  */
      do {
          printf("Enter A(dd), R(emove), D(isplay), or Q(uit)> ");
          scanf(" %c", &choice);
          switch (toupper(choice)) {
          case 'A':
                printf("Enter passenger data> ");
                scan_passenger(&next_pass);
                add_to_q(&pass_q, next_pass);
                break;
(continued)
Figure 14.26  (continued)
          case 'R':
                if (pass_q.size > 0) {
                      fst_pass = remove_from_q(&pass_q);
                      printf("Passenger removed from queue: \n");
                      print_passenger(fst_pass);
                } else {
                      printf("Queue empty - no-one to delete\n");
                }
                break;
 
          case 'D':
                if (pass_q.size > 0)
                      display_q(pass_q);
                else
                      printf("Queue is empty\n");
                break;
 
          case 'Q':
                printf("Leaving passenger queue program with %d \n",
                       pass_q.size);
                printf("passengers in the queue\n");
                break;
 
          default:
                printf("Invalid choice -- try again\n");
          }
      } while (toupper(choice) != 'Q');
 
      return (0);
}