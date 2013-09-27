Figure 14.29  Functions add_to_q and remove_from_q
/*
 *  Adds ele at the end of queue accessed through qp
 *  Pre:  queue is not empty
 */
void
add_to_q(queue_t         *qp,  /* input/output - queue   */
         queue_element_t  ele) /* input - element to add */
{
      if (qp->size == 0) {                /* adds to empty queue	*/
            qp->rearp = (queue_node_t *)malloc(sizeof (queue_node_t));
            qp->frontp = qp->rearp;
      } else {                            /* adds to non-empty queue	*/
            qp->rearp->restp = 
                  (queue_node_t *)malloc(sizeof (queue_node_t));
            qp->rearp = qp->rearp->restp;
      }
      qp->rearp->element = ele;           /* defines newly added node	*/
      qp->rearp->restp = NULL;
      ++(qp->size);
}

/*
 *  Removes and frees first node of queue, returning value stored there.
 *  Pre:  queue is not empty
 */
queue_element_t
remove_from_q(queue_t *qp) /* input/output - queue */
{
      queue_node_t    *to_freep;    /* pointer to node removed	*/
      queue_element_t  ans;         /* initial queue value which is to  
be returned 	*/

      to_freep = qp->frontp;        /* saves pointer to node being 
deleted	*/
      ans = to_freep->element;       	/* retrieves value to return	*/
      qp->frontp = to_freep->restp;	/* deletes first node 	*/
      free(to_freep);            	/* deallocates space 	*/
      --(qp->size);

      if (qp->size == 0)          	/* queue's ONLY node was deleted	*/
            qp->rearp = NULL;
 
      return (ans);
}