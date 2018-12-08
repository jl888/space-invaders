/** 
 	@file display_aliens_task.c
	@author GitHub @ jl888
	@date 08/10/2016
	@brief This module is used to display the aliens on the LED matrix.
*/

#include "system.h"
#include "display.h"

#define ROW_SIZE 3
#define COLUMN_SIZE 5
#define READY 0
#define SET 1

int invaders_row = 0;  // Row currently selected in the invaders array
int invaders_col = 0;  // Column currently select in the invaders array

/* 
	The values in each column and row are set to 0 (ready) from initialization.
	0 = invader ready to be set
	1 = invader set
	-1 = invader dead 
*/
int invaders[ROW_SIZE][COLUMN_SIZE] = 
{
	{READY, READY, READY, READY, READY},
	{READY, READY, READY, READY, READY},
	{READY, READY, READY, READY, READY}
};

/*
  Displays the aliens on the LED matrix. Otherwise, resets the LED matrix if
  all the aliens are dead.
*/
void display_aliens_task (__unused__ void *data)
{	
	if (invaders_row < ROW_SIZE) {
		if (invaders[invaders_row][invaders_col] == READY) {
			invaders[invaders_row][invaders_col] = SET;
			display_pixel_set (invaders_col, invaders_row, 1);
			if (invaders_col < COLUMN_SIZE - 1) {
				invaders_col += 1;
			} else {
				invaders_row += 1;
				invaders_col = 0;
			}
		}
	}

	display_update ();
}
