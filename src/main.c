#include <stdio.h>
#include <unistd.h>
#include <ncurses.h>


int WIDTH = 20;
int HEIGHT = 10;

int WIN_POS_X = 1;
int WIN_POS_Y = 1;

WINDOW* main_win;

void draw_point(int, int);
void clear_point(int, int);

int main() {
	// initialized screen
	initscr();

	// cursor visiblity
	curs_set(2);

	// do not echo keystroke on terminal
	noecho();

	// initialized window
	main_win = newwin(HEIGHT, WIDTH, WIN_POS_Y, WIN_POS_X);
	refresh();

	// initialized border
	box(main_win, 0, 0);
	wrefresh(main_win);

	getch();

	int x, y = 1, prev_x = 0, prev_y = 0, st = 0;

	for(; y < HEIGHT - 1; y++) {
		for(x = 1; x < WIDTH - 1; x++) {
			if (st == 1) clear_point(prev_x, prev_y);
			draw_point(x, y);
			wrefresh(main_win);
			
			prev_x = x;
			prev_y = y;

			st = 1;

			getch();
		}
	}

	endwin();

	return 0;
}


void draw_point(int x, int y) {
	wmove(main_win, y, x);
	waddch(main_win, '*');
}

void clear_point(int x, int y) {
	wmove(main_win, y, x);
	waddch(main_win, ' ');
}
