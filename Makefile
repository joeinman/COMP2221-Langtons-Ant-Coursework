# Makefile For COMP2221 - Langtons Ant Coursework

CC      = gcc
CFLAGS  = -Wall -lncursesw -I.

DEPS    = langton.h visualiser.h
OBJ     = main.o langton.o visualiser.o 

%.o: %.c $(DEPS)
	$(CC) -c -o $@ $< $(CFLAGS)

all: $(OBJ)
	$(CC) -o ant $^ $(CFLAGS)

library:
	$(CC) *.c -c -fPIC $(CFLAGS)
	$(CC) *.o -shared -o libant.so $(CFLAGS)

clean:
	rm -rf ant libant.so *.o