#include <ncurses.h>
#include <render/main_window.h>


WINDOW* MAIN_WINDOW_PTR;

int MAIN_WINDOW_WIDTH = 20;
int MAIN_WINDOW_HEIGHT = 10;

int MAIN_WINDOW_POS_X = 1;
int MAIN_WINDOW_POS_Y = 1;

int MAIN_WINDOW_BORDER_WIDTH_X = 1;
int MAIN_WINDOW_BORDER_WIDTH_Y = 1;


void initialize_main_window()
{
    // initialized screen
	initscr();

	// cursor visiblity
	curs_set(2);

	// do not echo keystroke on terminal
	noecho();

    if (MAIN_WINDOW_PTR != NULL)
    {
        // log_error("already initialized");
        return;
    }

    MAIN_WINDOW_PTR = newwin(
        MAIN_WINDOW_HEIGHT,
        MAIN_WINDOW_WIDTH,
        MAIN_WINDOW_POS_Y,
        MAIN_WINDOW_POS_X
    );

    refresh();

    // using default box here
    box(MAIN_WINDOW_PTR, 0, 0);
}

void refresh_main_window()
{
    refresh();
    wrefresh(MAIN_WINDOW_PTR);
}

void close_main_window()
{
    endwin();
}