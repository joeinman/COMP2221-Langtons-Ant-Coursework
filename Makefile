# Makefile For COMP2221 - Langtons Ant Coursework

CC      = gcc
CFLAGS  = -Wall -lncursesw -I.

DEPS    = langton.h visualiser.h
OBJ     = main.o langton.o visualiser.o 

%.o: %.c $(DEPS)
	$(CC) -c -o $@ $< $(CFLAGS)

all: $(OBJ)
	$(CC) -o program $^ $(CFLAGS)

clean:
	rm -rf program *.o