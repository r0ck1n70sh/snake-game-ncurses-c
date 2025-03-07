#define SPACE ' '

#include <stdlib.h>
#include <string.h>
#include <ncurses.h>

#include <geometry/point.h>
#include <render/main_window.h>

#include <render/screen_buffer.h>


WINDOW* MAIN_WINDOW_PTR;

int MAIN_WINDOW_WIDTH;
int MAIN_WINDOW_HEIGHT;
int MAIN_WINDOW_BORDER_WIDTH_X;
int MAIN_WINDOW_BORDER_WIDTH_Y;

unsigned** GLOBAL_SCREEN_BUFFER;
int BUFFER_SIZE_X;
int BUFFER_SIZE_Y;


void initialize_screen_buffer()
{
    BUFFER_SIZE_X = MAIN_WINDOW_WIDTH - (2 * MAIN_WINDOW_BORDER_WIDTH_X);
    BUFFER_SIZE_Y = MAIN_WINDOW_HEIGHT - (2 * MAIN_WINDOW_BORDER_WIDTH_Y);

    GLOBAL_SCREEN_BUFFER = (unsigned**) malloc(
            BUFFER_SIZE_X * sizeof(unsigned*)
        );

    int idx;
    for (idx = 0; idx < BUFFER_SIZE_X; idx++)
    {
        GLOBAL_SCREEN_BUFFER[idx] = (unsigned *) malloc(
            BUFFER_SIZE_Y * sizeof(unsigned)
        );

        memset(
            GLOBAL_SCREEN_BUFFER[idx],
            SPACE,
            BUFFER_SIZE_Y * sizeof(unsigned)
        );
    }

    // log_info("intialized screen buffer");
}

void free_screen_buffer()
{
    int idx;
    for (idx = 0; idx < BUFFER_SIZE_X; idx++)
    {
        free(GLOBAL_SCREEN_BUFFER[idx]);
    }

    free(GLOBAL_SCREEN_BUFFER);

    // log_info("intialized screen buffer");
}

int is_pixel_free_on_buffer(Point* pt)
{
    return GLOBAL_SCREEN_BUFFER[pt->x][pt->y] == SPACE;    
}

void write_pixel_to_buffer(Point* pt, unsigned c)
{
    GLOBAL_SCREEN_BUFFER[pt->x][pt->y] = c;
}

void erase_pixel_to_buffer(Point* pt)
{
    GLOBAL_SCREEN_BUFFER[pt->x][pt->y] = SPACE;
}

// TODO:
//  change architecture of screen_buffer
//  use original buffer to tracker changes
//  and, only write for changes
void write_buffer_to_main_window()
{
    int x, y;
    int actual_x, actual_y;

    for (y = 0; y < BUFFER_SIZE_Y; y++)
    {
        for (x = 0; x < BUFFER_SIZE_X; x++)
        {
            actual_x = x + MAIN_WINDOW_BORDER_WIDTH_X;
            actual_y = y + MAIN_WINDOW_BORDER_WIDTH_Y;

            wmove(MAIN_WINDOW_PTR, actual_y, actual_x);

            waddch(MAIN_WINDOW_PTR, GLOBAL_SCREEN_BUFFER[x][y]);
        }
    }
}