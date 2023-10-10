#include <stdio.h>
#include <ncurses.h>
#include <geometry/point.h>

int main() {
	Point *pt = make_point(10, 10);

	initscr();
	printw("Hello World\n");
	getch();

	printw("Point %d, %d\n", pt->x, pt->y);
	refresh();

	getch();
	endwin();

	return 0;
}
