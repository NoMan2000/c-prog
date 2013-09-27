Figure 14.24  Structure Types for a Linked-List Implementation of a Stack
typedef char stack_element_t;

typedef struct stack_node_s {
      stack_element_t      element;
      struct stack_node_s *restp;
} stack_node_t;

typedef struct {
      stack_node_t *topp;
} stack_t;