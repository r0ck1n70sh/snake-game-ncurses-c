#ifndef RENDER_SCREEN_BUFFER_H
#define RENDER_SCREEN_BUFFER_H

#include <ncurses.h>
#include <geometry/point.h>


unsigned** GLOBAL_SCREEN_BUFFER;

int BUFFER_SIZE_X;
int BUFFER_SIZE_Y;


// call after initializing MAIN_WINDOW
// call before, calling any other function in this header 
void initialize_screen_buffer();

// call before end of program
void free_screen_buffer();

int is_pixel_free_on_buffer(Point*);

void write_pixel_to_buffer(Point*, unsigned);
void erase_pixel_to_buffer(Point*);

void write_buffer_to_main_window();


#endif