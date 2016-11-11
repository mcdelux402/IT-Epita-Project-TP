/* Linked lists */

# include <stdlib.h>
# include <string.h>

# include "list.h"
# include "tests.h"

void print_list(struct list *list)
{
  int line = 1;
  printf("[");
  if (list->next) {
    goto pastfst;
    while (list->next) {
      line += printf(";");
      if (line > 72) {
	printf("\n ");
	line = 1;
      }
    pastfst:
      line += printf(" %d", list->next->data);
      list = list->next;
    }
  }
  printf("]");
}


/*
 * Standard operations
 * We're working with sentinels and external allocation
 * This means that our lists always have a fake head (the sentinel)
 * and all allocations (and free) are performed by the caller, not the operation
 */

/*
 * list_init(list)
 * initialise the sentinel node list
 */
void list_init(struct list *list)
{
  list -> data = 0;
  list -> next = NULL;
}
/*
 * list_is_empty(list)
 * returns true if the list is empty
 * remember, we have a sentinel thus a list always has at least one node,
 * the list is empty if this node doesn't have a next.
 */
int list_is_empty(struct list *list)
{ if (list -> next == NULL)
    return 0;
  return 1;
}

/*
 * list_len(list)
 * returns the length of the list (don't count the sentinel)
 */
size_t list_len(struct list *list)
{
  size_t i = 0;
  for(; list != NULL; list = list -> next)
    i++;
  return i;
}

/*
 * list_push_front(list, elm)
 * attach elm in front of list, that is after the sentinel.
 * Note that elm is already a node, you just have to attach it.
 */
void list_push_front(struct list *list, struct list *elm)
{
  elm -> next = list -> next;
  list -> next = elm;
}

/*
 * list_pop_front(list)
 * Extract the first element (not the sentinel) of list.
 * This operation detaches the element from the list and returns it (caller is
 * responsible for freeing it.)
 * If the list is empty, the function returns NULL.
 */
struct list* list_pop_front(struct list *list)
{
  if (list && list -> next)
    {
      struct list *stl;
      stl = list -> next;
      list = stl;
      return list;
    }
  return NULL;
}

/*
 * list_find(list, value)
 * search for the first node containing value and returns (without detaching it)
 * the corresponding list node. The function returns NULL if the value is not
 * present in the list.
 */
struct list* list_find(struct list *list, int value)
{
  while (list -> next != NULL && list -> data != value)
    list = list -> next;
  if (list -> data == value)
    return list;
  return NULL;
}

/*
 * list_is_sorted(list)
 * check whether the list is sorted in increasing order
 */
int list_is_sorted(struct list *list)
{
  while (list -> next != NULL && list -> data < list -> next -> data)
    list = list -> next;
  if (list -> next == NULL)
    return 1;
  return 0;
}

/*
 * list_insert(list, elm)
 * insert elm in the sorted list (keeping the list sorted)
 * Like list_push_front, elm is already a list node.
 */
void list_insert(struct list *list, struct list *elm)
{
  while (list -> next != NULL && list -> data < list -> next -> data)
    list = list -> next;
  if (list -> next != NULL)
    {
      elm -> next = list -> next;     
    }
  list -> next = elm;
}

/*
 * More algorithms
 */

/*
 * list_rev(list)
 * reverse the list using the same nodes (just move them) and the same sentinel.
 */
void list_rev2(struct list *list){
  if(list -> next -> next){
    struct list *prev = malloc(sizeof(struct list));
    struct list *prev2 = malloc(sizeof(struct list));
    struct list *prev3 = malloc(sizeof(struct list));
    prev = NULL;
    prev2 = list -> next;
    prev3 = prev2 -> next;
    while(prev3 != NULL){
      prev2 -> next = prev;
      prev = prev2;
      prev2 = prev3;
      prev3 = prev3 -> next;
    }
    prev2 -> next = prev;
    list -> next = prev2;
  }
}

void list_rev(struct list *list)
{
  size_t i = 0;
  struct list *cur;
  struct list *stl = list;
  int change;
  while (list -> next != NULL)
    {
      list = list -> next;
      i++;
    }
  cur = list;
  list = stl -> next;
  change = list -> data;
  list -> data = cur -> data;
  cur -> data = change;
  while (list != cur)
    {
      cur = list;
      for(size_t j = 1; i - j > 0; j++ )
	{
	  cur = cur -> next;
	}
      change = list -> data;
      list -> data = cur -> data;
      cur -> data = change;
      list = list -> next;
      //i++;
    }
}

/*
 * list_half_split(list, second)
 * split the list in half and put the second half in second
 * second is an empty list (just a sentinel)
 */
void list_half_split(struct list *list, struct list *second)
{
  size_t i = 0;
  struct list *stl = list;
  for(; list -> next != NULL; list = list -> next)
    i++;
  list = stl;
  size_t mid = i / 2;
  for(; mid > 0; mid --)
    list = list -> next;
  for(; list -> next != NULL; list = list -> next)
    list_insert(second, list);
}


int main(){
  struct list *liste = malloc(sizeof(struct list));
  list_init(liste);
  //printf("%d\n", list_is_empty(liste));
  /*struct list *liste2 = malloc(sizeof(struct list));
    liste2 -> data = 60;
    list_push_front(liste, liste2);
    struct list *liste4 = malloc(sizeof(struct list));
        liste4 -> data = 42;
        list_push_front(liste, liste4);
	printf("%zu\n", list_len(liste));
	print_list(liste);
	printf("\n");*/
  //struct list *liste3 = malloc(sizeof(struct list));
  //list_init(liste3);
  //liste3 = list_pop_front(liste);
  //print_list(liste3);
  //printf("\n");
  //print_list(liste);
  /*struct list *liste5 = malloc(sizeof(struct list));
        list_init(liste5);
	liste5 -> next = list_find(liste, 60);
	print_list(liste5);*/
  printf("is sorted:");
  printf("\n");
  printf("%d\n", list_is_sorted(liste));
  struct list *liste6 = malloc(sizeof(struct list));
  liste6 -> data = 61;
  printf("Insertion de:");
  print_list(liste);
  print_list(liste6);
  list_insert(liste, liste6);
  printf("\n");
  print_list(liste);
  //print_list(liste);
  printf("\n");
  
  struct list *liste8 = malloc(sizeof(struct list));
  liste8 -> data = 69;
  printf("Insertion de:");
  print_list(liste);
  print_list(liste8);
  printf("\n");
  list_insert(liste, liste8);
  // print_list(liste);
  print_list(liste);
  printf("\n");
  
  
  struct list *liste7 = malloc(sizeof(struct list));
  liste7 = liste;
  printf("List_rev de");
  print_list(liste7);
  printf("\n");
  list_rev(liste7);
  print_list(liste7);
  printf("\n");
  
  //print_list(liste);
  struct list *liste9 = malloc(sizeof(struct list));
  list_init(liste9);
  printf("Half split");
  printf("\n");
  print_list(liste);
  printf("\n");
  
  list_half_split(liste, liste9);
  print_list(liste9);
  printf("\n");
  //print_list(liste);
  //free(liste3);
  free(liste);
  return 0;
}
