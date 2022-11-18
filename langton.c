#include "langton.h"

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
    if      (ant->direction == UP)    ant->y -= 1;
    else if (ant->direction == RIGHT) ant->x += 1;
    else if (ant->direction == DOWN)  ant->y += 1;
    else if (ant->direction == LEFT)  ant->x -= 1;
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
