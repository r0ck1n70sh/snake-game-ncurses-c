#ifndef SNAKE_H
#define SNAKE_H

#include <point.h>


typedef struct {
	int len;
	Point * head;	
} Snake;


Snake * make_snake (Point[], int);


#endif
