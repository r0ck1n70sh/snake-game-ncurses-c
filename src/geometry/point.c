#include <stdlib.h>
#include <geometry/point.h>


Point * make_point (int x, int y) {
	Point *pt = (Point *) malloc(sizeof(Point));

	pt->x = x;
	pt->y = y;

	return pt;
}

