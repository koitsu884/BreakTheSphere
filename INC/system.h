#ifndef _MY_SYSTEM_INCLUDE
#define _MY_SYSTEM_INCLUDE


typedef struct {
    float   x, y;
} KEY_MOV_TABLE;

typedef struct {
    float   x, y;
} POINT2D;

typedef struct {
	POINT2D	pos;
	POINT2D mov;
} BALL;

#endif