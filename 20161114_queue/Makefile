CC=gcc
CFLAGS=-Wall -Wextra  -pedantic -std=c99

QUEUE_SRC= queue.c testing.c
TREE_SRC = queue.c tree.c
.PHONY: queue tree clean

queue:
	$(CC) $(CFLAGS) $(QUEUE_SRC) -o queue -g

tree:
	$(CC) $(CFLAGS) $(TREE_SRC) -o tree -g

clean:
	$(RM) queue
	$(RM) tree
