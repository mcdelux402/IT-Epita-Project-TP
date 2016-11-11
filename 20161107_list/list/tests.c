# include <stdlib.h>
# include <string.h>

# include "tests.h"
# include "list.h"

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
  printf(" ]\n");
}

/*
void list_insert_sort(struct list *list)
{
  if (list_is_empty(list)        // nothing to do
      return;
      struct list fake_head = {0,0}; // temporary head
      while (!list_is_empty(list)) {
	struct list *elm = list_pop_front(list);
	list_insert(&fake_head, elm);
      }
      list->next = fake_head.next;   // reattach the sorted list to its sentinel
      }
*/