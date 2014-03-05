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

int snake_body_size = 1;

int timer_speed = 150;
int fruit_timer_speed = 3000;

typedef struct pos_snake_part_ {
    int x;
    int y;
    struct pos_snake_part_ *next;
} pos_snake_part;
typedef pos_snake_part* list_snake_parts;
list_snake_parts snake = NULL;

GLvoid *font_style = GLUT_BITMAP_TIMES_ROMAN_24;

typedef enum { false, true } bool;
bool pause;

static GLuint texName[NB_TEXTURES];
GLubyte* data;

#endif // VARS_H_INCLUDED
