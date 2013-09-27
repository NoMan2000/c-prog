Figure 14.26  Structure Types for a Linked-List Implementation of a Queue
/*  Insert typedef for queue_element_t */
 
typedef struct queue_node_s {
      queue_element_t      element;
      struct queue_node_s *restp;
} queue_node_t;
 
typedef struct {
      queue_node_t *frontp,
                   *rearp;
      int           size;
} queue_t;