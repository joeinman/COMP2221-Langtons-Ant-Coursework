#include "langton.h"

void turn_left(struct ant *ant)
{
    switch (ant->direction)
    {
    case UP:
        ant->direction = LEFT;
        break;
    case LEFT:
        ant->direction = DOWN;
        break;
    case DOWN:
        ant->direction = RIGHT;
        break;
    case RIGHT:
        ant->direction = UP;
        break;
    }
}

void turn_right(struct ant *ant)
{
    switch (ant->direction)
    {
    case UP:
        ant->direction = RIGHT;
        break;
    case RIGHT:
        ant->direction = DOWN;
        break;
    case DOWN:
        ant->direction = LEFT;
        break;
    case LEFT:
        ant->direction = UP;
        break;
    }
}

void move_forward(struct ant *ant)
{
    if(ant->direction == UP)    ant->y -= 1;
    else if(ant->direction == RIGHT) ant->x += 1;
    else if(ant->direction == DOWN)  ant->y += 1;
    else if(ant->direction == LEFT)  ant->x -= 1;
}

void apply_rule(enum colour *colour, struct ant *ant)
{
    switch (*colour)
    {
    case WHITE:
        turn_left(ant);
        *colour = BLACK;
        break;
    case BLACK:
        turn_right(ant);
        *colour = WHITE;
        break;
    }
}

void apply_rule_general(enum colour *colour, struct ant *ant, struct rule *rule)
{
    
}
