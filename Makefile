CC      = gcc
CFLAGS  = -Wall -lncursesw -I.

SRC_DIR = src
DEPS    = $(SRC_DIR)/langton.h $(SRC_DIR)/visualiser.h
OBJ     = $(SRC_DIR)/main.o $(SRC_DIR)/langton.o $(SRC_DIR)/visualiser.o 

%.o: %.c $(DEPS)
	$(CC) -c -o $@ $< $(CFLAGS)

all: $(OBJ)
	$(CC) -o program $^ $(CFLAGS)

clean:
	rm -rf program $(SRC_DIR)/*.o