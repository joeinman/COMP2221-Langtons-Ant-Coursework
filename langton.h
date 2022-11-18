#ifndef langton_h
#define langton_h

#include <string.h>

enum direction { UP, DOWN, LEFT, RIGHT };

struct ant {
    int x;
    int y;
    enum direction direction;
};

struct rule {
    char* rules;
};

#define ant_is_at(y, x) ant->x == x && ant->y == y

enum colour { WHITE, BLACK };

void turn_left(struct ant *ant);
void turn_right(struct ant *ant);
void move_forward(struct ant *ant);

// void apply_rule(enum colour *colour, struct ant *ant);
void apply_rule_general(int *colour, struct ant *ant, struct rule *rule);

#endif
