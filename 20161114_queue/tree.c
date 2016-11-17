/* tree.c: testing queue using binary trees */

# include <assert.h>
# include <err.h>
# include <stdio.h>
# include <stdlib.h>

# include "queue.h"

struct tree {
  struct tree *left, *right;
  int key;
};

struct tree* build_tree(long depth, int *key)
{
  struct tree *node = NULL;
  if (depth >= 0) {
    node = malloc(sizeof (struct tree));
    if (!node)
      err(1, "tree node allocation failed, dying");
    node->left = build_tree(depth - 1, key);
    *key += 1;
    node->key = *key;
    node->right = build_tree(depth - 1, key);
  }
  return node;
}

void bfs(struct tree *root)
{
  struct queue *queue;
  if (root)
    {
      queue_init(queue);
      queue_push(queue, root);
      queue_push(queue, NULL);
      struct queue *q;
      while(queue_is_empty(queue) == 0)
	{
	  q = queue_pop(queue);
	  if (q)
	    {
	      printf(q -> key);
	      printtf(" ");
	      if (q -> left)
		  queue_push(queue, node -> left);
	      if (q -> right)
		queue_push(queue, node -> right);
	    }
	  else
	    {
	      printf("");
	      if(queue_is_empty(queue) == 0)
		queue_push(queue, NULL);
	    }
	}
    }
}

void delete_tree(struct tree *root)
{
  if (root) {
    delete_tree(root->left);
    delete_tree(root->right);
    free(root);
  }
}

int main(int argc, char *argv[])
{
  long depth = 3;
  if (argc > 1)
    depth = strtol(argv[1], NULL, 10);
  int key = 0;
  struct tree *root = build_tree(depth, &key);
  bfs(root);
  delete_tree(root);
  return 0;
}
