CFLAGS = -Wall -lncursesw
SRC_DIR = src

all: langton.o visualiser.o $(SRC_DIR)/main.c
	gcc -o program $(SRC_DIR)/main.c langton.o visualiser.o $(CFLAGS)

langton.o: $(SRC_DIR)/langton.c $(SRC_DIR)/langton.h
	gcc -c $(SRC_DIR)/langton.c $(CFLAGS)

visualiser.o: $(SRC_DIR)/visualiser.c $(SRC_DIR)/visualiser.h
	gcc -c $(SRC_DIR)/visualiser.c $(CFLAGS)

clean:
	rm -rf program test langton.o visualiser.o

test: tests/ncurses_test.c
	gcc -o test tests/ncurses_test.c $(CFLAGS)