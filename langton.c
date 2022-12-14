#include <string.h>
#include "langton.h"
#include <ncurses.h>

void turn_left(struct ant *ant) {
    if      (ant->direction == UP)    ant->direction = LEFT;
    else if (ant->direction == RIGHT) ant->direction = UP;
    else if (ant->direction == DOWN)  ant->direction = RIGHT;
    else if (ant->direction == LEFT)  ant->direction = DOWN;
}

void turn_right(struct ant *ant) {
    if      (ant->direction == UP)    ant->direction = RIGHT;
    else if (ant->direction == RIGHT) ant->direction = DOWN;
    else if (ant->direction == DOWN)  ant->direction = LEFT;
    else if (ant->direction == LEFT)  ant->direction = UP;
}

void move_forward(struct ant *ant) {
    if (ant->direction == UP) {
        if(ant->y == 0) ant->y = getmaxy(stdscr) - 1;
        else ant->y -= 1;
    }

    else if (ant->direction == RIGHT) {
        if(ant->x == getmaxx(stdscr) - 1) ant->x = 0;
        else ant->x += 1;
    }

    if (ant->direction == DOWN) {
        if(ant->y == getmaxy(stdscr) - 1) ant->y = 0;
        else ant->y += 1;
    }

    else if (ant->direction == LEFT) {
        if(ant->x == 0) ant->x = getmaxx(stdscr) - 1;
        else ant->x -= 1;
    }
}

void apply_rule(enum colour *colour, struct ant *ant) {
    if (*colour == WHITE) {
        turn_left(ant);
        *colour = BLACK;
    } else {
        turn_right(ant);
        *colour = WHITE;
    }
}

void apply_rule_general(int *colour, struct ant *ant, struct rule *rule) {
    // Turn Ant
    if (rule->rules[*colour] == 'L')
        turn_left(ant);
    else
        turn_right(ant);

    // Increment State
    if (*colour < (int)strlen(rule->rules) - 1)
        (*colour)++;
    else
        *colour = 0;
}
