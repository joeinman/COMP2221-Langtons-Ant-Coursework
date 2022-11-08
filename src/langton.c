#include "langton.h"

void turn_left(struct ant *ant)
{
    if(ant->direction == UP) ant->direction = LEFT;
    if(ant->direction == LEFT) ant->direction = DOWN;
    if(ant->direction == DOWN) ant->direction = RIGHT;
    if(ant->direction == RIGHT) ant->direction = UP;
}

void turn_right(struct ant *ant)
{
    if(ant->direction == UP) ant->direction = RIGHT;
    if(ant->direction == RIGHT) ant->direction = DOWN;
    if(ant->direction == DOWN) ant->direction = LEFT;
    if(ant->direction == LEFT) ant->direction = UP;
}

void move_forward(struct ant *ant)
{
    if(ant->direction == UP) ant->y += 1;
    if(ant->direction == RIGHT) ant->x += 1;
    if(ant->direction == DOWN) ant->y -= 1;
    if(ant->direction == LEFT) ant->x -= 1;
}

void apply_rule(enum colour *colour, struct ant *ant)
{
    if(*colour == WHITE)
    {
        turn_left(ant);
        *colour = BLACK;
    }

    if(*colour == BLACK)
    {
        turn_right(ant);
        *colour = WHITE;
    }
}

void apply_rule_general(enum colour *colour, struct ant *ant, struct rule *rule)
{
    
}
