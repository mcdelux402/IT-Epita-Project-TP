# include <stdlib.h>
# include <string.h>
# include <stdio.h>
# include "vector.h"

/*
 * vector_make(capacity) create an empty vector
 * with initial storage size capacity
 */
struct vector* vector_make(size_t capacity)
{
  struct vector *vect;
  vect -> capacity = capacity;
  vect -> size = 0;
  vect -> data = NULL;
  return vect;
}

/*
 * vector_push_back(vect, x) add x at the end of vect
 * if vect is full increase capacity
 */
void vector_push_back(struct vector *vect, int x)
{
  if (vect -> capacity == vect -> size)
    vect -> capacity += 1;
  vect -> size += 1;
  size_t i = 0;
  while(vect -> data[i] != NULL)
    i++;
  vect -> data[i] = x;
}

/*
 * vector_pop_back(vect, &x) get the last element of vect
 * remove the element
 * store result in x
 * return true (!=0) if size > 0
 * return false (0) otherwise
 */
int  vector_pop_back(struct vector *vect, int *x)
{
  size_t i = 0;
  while(vect -> data[i] != NULL)
    i++;
  *x = vect -> data[i];
  vect -> data[i] = NULL;
  vect -> size -= 1;
  if (vect -> size < 0)
    return 0;
  return 1;
}

/*
 * vector_push_front(vect, x) add x at the beginning of vect
 * if vect is full increase capacity
 */
void vector_push_front(struct vector *vect, int x)
{
  size_t i = 0;
  if (vect -> size == vect -> capacity)
    vect -> capacity += 1;
  vect -> size += 1;
  while(vect -> data[i+1] != NULL)
    {
      i++;
      vect -> data[i+1] = vect -> data[i];
    }
  vect -> data[0] = x;
}

/*
 * vector_pop_back(vect, &x) get the first element of vect
 * remove the element
 * store result in x
 * return true (!=0) if size > 0
 * return false (0) otherwise
 */
int  vector_pop_front(struct vector *vect, int *x)
{
  size_t i = 0;
  *x = vect -> data[i];
  while(vect -> data[i+1] != NULL)
    {
      vect -> data[i] = vect -> data[i+1];
      i++;
    }
  vect -> size -= 1;
  vect -> data[i] = NULL;
  return *x;
}

/*
 * vector_insert_at(vect, pos, x) add x in pos cell of vect
 * return true (!=0) if pos <= size of vect
 * return false (0) otherwise
 * vector_insert_at(v, v->size, x) is equivalent to vector_push_back(v, x)
 * vector_insert_at(v, 0, x) is equivalent to vector_push_front(v, x)
 * if vect is full increase capacity
 */
int vector_insert_at(struct vector *vect, size_t pos, int x)
{
  if (pos == vect -> size)
    {
      vector_push_back(vect, x);
      return 1;
    }
  else
    {
      if(pos == 0)
	{
	  vector_push_front(0, x);
	  return 0;
	}
      else
	{
	  if(vect -> size == vect -> capacity)
	    vect -> capacity += 1;
	  vect -> size += 1;
	  for(size_t i = pos; vect -> data[i+1] != NULL; i++)
	    {
	      vect -> data[i+1] = vect -> data[i]; 
	    }
	  vect -> data[pos] = x;
	  return 1;
	}
    }  
  
}

/*
 * vector_extract_at(vect, pos, &x) get the pos element of vect
 * remove the element
 * store result in x
 * return false (0) if size == 0 or pos >= size
 * vector_extract_at(v, v->size - 1, &x) is equivalent to vector_pop_back(v, &x)
 * vector_extract_at(v, 0, &x) is equivalent to vector_pop_front(v, &x)
 */
int vector_extract_at(struct vector *vect, size_t pos, int *x);

/*
 * vector_clone(vect) create a complete copy of vect
 * both storage contains the same elements but are not at the same memory place
 */
struct vector* vector_clone(struct vector *vect);


void print_tab(struct vector *vect){
  int line = 1;
  printf("[");
  size_t i = 0;
  while(i < vect->size){
    line += printf(";");
    if(line > 72){
      printf("\n");
      line = 1;
    }
    line += printf(" %d", vect->data[i]);
    i++;
  }
  printf(" ]\n");
}

int main() {
  struct vector *vect = vector_make(5);
  for(int i = 9; i >= 0; --i)
    vector_push_front(vect, i);
  print_tab(vect);
  for(int i = 9; i >= 0; --i)
    vector_push_back(vect, i);
  print_tab(vect);
  vector_insert_at(vect, 10, 42);
  vector_insert_at(vect, 0, -1);
  vector_insert_at(vect, vect->size, -666);
  print_tab(vect);
  int a;
  vector_extract_at(vect, vect->size-1, &a);
  int b;
  vector_extract_at(vect, 0, &b);
  int c;
  vector_extract_at(vect, 10, &c);
  printf("%d %d %d:", a, b, c);
  print_tab(vect);
  struct vector *clone = vector_clone(vect);
  vector_push_back(vect, 1337);
  int d;
  vector_pop_front(clone, &d);
  printf("%d:", d);
  print_tab(clone);
  print_tab(vect);
  int x;
  while(vector_pop_back(vect, &x))
    printf("%d; ", x);
  printf("\n");
  print_tab(vect);
}
