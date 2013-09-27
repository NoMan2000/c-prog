Figure 14.32  Building an Ordered List through Insertions and Deletions
/*
 *  Program that builds an ordered list through insertions and then modifies
 *  it through deletions.
 */

#include <stdio.h>

typedef struct list_node_s {
      int                 key;
      struct list_node_s *restp;
} list_node_t;
 
typedef struct {
      list_node_t *headp;
      int          size;
} ordered_list_t;

list_node_t *insert_in_order(list_node_t *old_listp, int new_key);
void insert(ordered_list_t *listp, int key);
int delete(ordered_list_t *listp, int target);
void print_list(ordered_list_t list);

#define SENT -999

int
main(void)
{
      int            next_key;
      ordered_list_t my_list = {NULL, 0};

      /* Creates list through in-order insertions */
      printf("Enter integer keys--end list with %d\n", SENT);
      for  (scanf("%d", &next_key);
	    next_key != SENT;
	    scanf("%d", &next_key)) {
	  insert(&my_list, next_key);
      }

      /* Displays complete list */
      printf("\nOrdered list before deletions:\n");
      print_list(my_list);

      /* Deletes nodes as requested */
      printf("\nEnter a value to delete or %d to quit> ", SENT);
      for  (scanf("%d", &next_key);
	    next_key != SENT;
	    scanf("%d", &next_key)) {
	  if (delete(&my_list, next_key)) {
		printf("%d deleted.  New list:\n", next_key);
		print_list(my_list);
	  } else {
		printf("No deletion.  %d not found\n", next_key);
	  }
      }

      return (0);
}

Enter integer keys--end list with -999
5  8  4  6  -999
Ordered list before deletions:
   size = 4
   list = 4
	  5
	  6
	  8

Enter a value to delete or -999 to quit> 6
6 deleted.  New list:
   size = 3
   list = 4
          5
          8
 
Enter a value to delete or -999 to quit> 4
4 deleted.  New list:
   size = 2
   list = 5
          8
 
Enter a value to delete or -999 to quit> -999