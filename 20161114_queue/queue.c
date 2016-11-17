# include "queue.h"

/*
 * queue_init(queue) initialize an empty queue container
 * allocation of the container is kept external for more flexibility
 */
void queue_init(struct queue *queue)
{
  struct list* list = malloc(sizeof (struct list));
  list -> data = NULL;
  list -> next = NULL;
  queue -> store = list;
  queue -> size = 0;
}

/*
 * queue_is_empty(queue) test for emptyness
 */
int queue_is_empty(struct queue *queue)
{
  if(queue -> size == 0)
    return 1;
  return 0;
}

/*
 * queue_push(queue, elm) push elm
 */
void queue_push(struct queue *queue, void *elm)
{
  struct queue *q;
  q -> store -> data =  *elm;
  q ->  store -> next = queue -> store -> next;
  queue -> store -> next = q; 
  queue -> size += 1;
  queue = q;
}

/*
 * queue_pop(queue) pop the next element (FIFO order)
 * returns NULL if the queue is empty
 */
void* queue_pop(struct queue *queue)
{
  if (queue -> size == 0)
    {
      return NULL;
    }
  struct queue * q;
  q = queue -> store -> next; 
  queue -> store -> next = queue -> store -> next -> next;
  queue -> size = -= 1;
  q -> store -> data = NULL;
}
