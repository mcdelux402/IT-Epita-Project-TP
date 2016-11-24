# ifndef _HASH_TABLE_H_
# define _HASH_TABLE_H_

# include <stdint.h>
# include <stdlib.h>
# include "hash_table.h"

/*
 * hash(data):
 * compute the hash of the nul terminated string data.
 */
uint32_t hash(char *data) 
{
  uint32_t h = 0;
  while( *data != 0)
    {
      uint32_t val = *data; 
      h += val;
      data = data + 1;
      h += 1024 * h;
      h = h^(h/64);
    }
  h += h 2048;
  h = h ^ (h/2048);
  h += h * 32768;
  return h;
}
/*
 * create_htable(capacity):
 * build a new hash table with initial capacity.
 */
struct htable *create_htable(size_t capacity)
{
  struct htable *table = malloc(sizeof(struct htable *table));
  table -> size = 0;
  table -> capacity = capacity;
  struct pair **par = malloc(sizeof(struct pair *par));
  table -> pair = par;
  par -> hkey = 0;
  par -> key = [NULL];
  par -> next = NULL;
}
/*
 * access_htable(htable, key):
 * returns a pointer to the pair containing the given key
 */
struct pair *access_htable(struct htable *htable, char *key)
{
  
}
/*
 * add_htable(htable,key,value):
 * add the pair (key,value) to the hash table
 */
int add_htable(struct htable *htable, char *key, void *value);

/*
 * remove_htable(htable, key):
 * removes the pair containing the given key from the hash table
 */
void remove_htable(struct htable *htable, char *key);

/*
 * clear_htable(htable):
 * delete all pairs in the table
 */
void clear_htable(struct htable *htable);

