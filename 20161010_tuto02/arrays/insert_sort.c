# include <stdlib.h>	       
# include <string.h>

# include "insert_sort.h"

// insert using the naive algo

void array_insert(int *begin, int *end, int x)
{
  while(begin < end && x < *(end-1))
    {
      *end = *(end - 1);
      --end;
    }
  *end = x;  
}



int* bin_search(int x, int *begin, int *end)
{
  int *mid;
  if (begin == end)
    return(end);
  mid = begin + (end - begin) / 2;
  if(*mid == x)
    return(mid);
  if(x < *mid)
    return (bin_search(x, begin , mid));
  else
    return(bin_search(x , mid+1, end));
}

// insert using binary search

void array_insert_bin(int *begin, int *end, int x)
{
  int* i = bin_search(x, begin, end);
  int* j = end;
  while(j > i)
    {
      *j = *(j - 1);
      --j;
    }
  *i = x;
}



void array_insert_sort(int *begin, int *end)
{
  int* debut = begin;
  for(; debut != end ; ++debut)
    array_insert(begin, debut, *debut);
}



void array_insert_sort_bin(int *begin, int *end)
{
  int* debut = begin;
  for(; debut != end ; ++debut)
    array_insert_bin(begin, debut, *debut);
}

