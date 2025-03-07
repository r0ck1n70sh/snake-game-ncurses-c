#ifndef RENDER_MAIN_WINDOW_H
#define RENDER_MAIN_WINDOW_H

#include <ncurses.h>

extern WINDOW* MAIN_WINDOW_PTR;

extern int MAIN_WINDOW_WIDTH;
extern int MAIN_WINDOW_HEIGHT;

extern int MAIN_WINDOW_POS_X;
extern int MAIN_WINDOW_POS_Y;

extern int MAIN_WINDOW_BORDER_WIDTH_X;
extern int MAIN_WINDOW_BORDER_WIDTH_Y;


// call only once, during start
void initialize_main_window();

// call only when required to render changes
void refresh_main_window();

// call only before end of program
void close_main_window();

#endif
