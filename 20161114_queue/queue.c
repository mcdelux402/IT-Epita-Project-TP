# include <assert.h>
# include <err.h>
# include <stdio.h>
# include <stdlib.h>

# include "queue.h"

void print_(struct queue *t);

/*
 * queue_init(queue) initialize an empty queue container
 * allocation of the container is kept external for more flexibility
 */
void queue_init(struct queue *queue)
{
  // list -> data = NULL;
  //list -> next = NULL;
  queue -> store = NULL;
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
  struct list * list = malloc(sizeof(list));
  list -> data = elm;
  if(queue -> size == 0)
    {
      list -> next = list;
      queue -> store = list;
    }
  else
    {
      list -> next = queue -> store -> next ;
      queue -> store -> next = list;
      queue -> store = list;
    }
  queue -> size += 1;
}

void queue_push1(struct queue *queue, void *elm)
{
  struct list *tmp = malloc(sizeof(struct list));
  tmp -> data = elm;
  if (queue)
    {
      tmp -> next = queue -> store -> next;
      queue -> store -> next = tmp;
    }
  else
    {
      tmp -> next = tmp;
    }
  queue -> size = queue -> size + 1;
  queue -> store = tmp;
  free(tmp);
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
  struct list *listNext = queue -> store -> next;
  //struct queue *queueNext;
  listNext  = queue -> store -> next;
  void *q1 = listNext -> data;
  if(queue -> size  == 1)
    {
      queue -> store = NULL;
    }
  else
    {
      queue -> store -> next = listNext -> next;
    }
  queue -> size = queue -> size - 1;
  return q1;
}

void* queue_pop1(struct queue * queue)
{
  void *elm;
  struct list *list;
  if (queue -> size - 1 == 0)
    {
      elm = queue -> store -> next -> data;
      queue -> store -> next = NULL;
      list = queue -> store;
      queue -> store = NULL;
    }
  else
    {
      list = queue -> store -> next;
      elm = list -> data;
      queue -> store -> next = list -> next;
    }
  free(list);
  queue -> size -=1;
  return elm;
}

/*
void print_(struct queue *q)
{
  struct list *l = q->store;
  for (size_t i = q->size; i < q->size; i++)
    {
      int *j = l->data;
      printf("|%i", *j);
      l = l->next;
    }
  printf("|\n");
}
*/
