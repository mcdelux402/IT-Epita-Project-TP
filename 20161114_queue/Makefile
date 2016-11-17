# Makefile
# Tom Decrette

# Compilers and options
CC=gcc
CPPFLAGS= -MMD
CFLAGS= -Wall -Wextra -std=c99 -g
LDFLAGS=
LDLIBS=

SRC = queue.c testing.c tree.c
OBJ = ${SRC:.c=.o}
DEP = ${SRC:.c=.d}

all: testing tree

testing: queue.o testing.o

-include queue.d testing.d

tree: queue.o tree.o

-include queue.d tree.d

clean:
	rm -f ${OBJ} ${DEP}
	rm -f testing tree

# END

