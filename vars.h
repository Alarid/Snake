#ifndef VARS_H_INCLUDED
#define VARS_H_INCLUDED

float ex=10;
float ey=23;
float ez=28;

typedef enum {
    EMPTY,
    SNAKE_HEAD,
    SNAKE_BODY,
    FRUIT,
} map_elem;
map_elem map[PLATEAU_WIDTH][PLATEAU_WIDTH];

typedef enum { LEFT, RIGHT, UP, DOWN } _direction;
_direction direction;

int snake_body_size = 3;

int timer_speed = 150;

typedef struct {
    int x;
    int y;
    struct pos_snake_part *next;
} pos_snake_part;
typedef pos_snake_part* list_snake_parts;
list_snake_parts snake = NULL;

#endif // VARS_H_INCLUDED
