#include <stdio.h>
#include <unistd.h>
#include <ncurses.h>

#include <render/main_window.h>
#include <render/screen_buffer.h>

WINDOW* MAIN_WINDOW_PTR;

int MAIN_WINDOW_WIDTH;
int MAIN_WINDOW_HEIGHT;

int BUFFER_SIZE_X;
int BUFFER_SIZE_Y;

// void draw_point(int, int);
// void clear_point(int, int);

int main() {

	initialize_main_window();
	refresh_main_window();

	getch();

	initialize_screen_buffer();

	int x, y = 1, prev_x = 0, prev_y = 0, st = 0;

	// for(; y < MAIN_WINDOW_HEIGHT - 1; y++) {
	// 	for(x = 1; x < MAIN_WINDOW_WIDTH - 1; x++) {
	// 		if (st == 1) clear_point(prev_x, prev_y);
	// 		draw_point(x, y);
	// 		refresh_main_window();
			
	// 		prev_x = x;
	// 		prev_y = y;

	// 		st = 1;

	// 		getch();
	// 	}
	// }

	Point* curr_pt = make_point(1, 1);	

	for(y = 0; y < BUFFER_SIZE_Y; y++) {
		for(x = 0; x < BUFFER_SIZE_X; x++) {
			curr_pt->x = x;
			curr_pt->y = y;

			write_pixel_to_buffer(curr_pt, '*');
			write_buffer_to_main_window();
			refresh_main_window();
			
			getch();
			erase_pixel_to_buffer(curr_pt);
		}
	}

	free_screen_buffer();
	close_main_window();

	return 0;
}

// not using combination method here
// due to side effects 

// void draw_point(int x, int y) {
// 	wmove(MAIN_WINDOW_PTR, y, x);
// 	waddch(MAIN_WINDOW_PTR, '*');
// }

// void clear_point(int x, int y) {
// 	wmove(MAIN_WINDOW_PTR, y, x);
// 	waddch(MAIN_WINDOW_PTR, ' ');
// }
