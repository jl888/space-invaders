/** 
	@file alien_fire_task.c
	@author GitHub @ jl888
	@date 08/10/2016
	@brief This module uses a random number generator to select a column within the grid.
	The alien first in line will be used for shooting.
*/

#include <stdlib.h>
#include "system.h"
#include "display_aliens_task.h"

#define ALIEN_FIRE_RATE 70
#define SET 1

int enemy_fire_row = 0;		// Tracking the row location of the missile
int enemy_fire_col = 0;		// Tracking the col location of the missile


/*
	This function randomly selects an alien to shoot from in a random column 
	where at least 1 alien is still alive.
*/
void alien_fire_task (__unused__ void *data)
{
	static int random_column = 0;
	static int in_progress = 0;		// checks if shooting is still in progress
	static int tick = 0;
	static int starting_row = 3;
	static int fire_rate_counter = 0;
	
	if (fire_rate_counter < ALIEN_FIRE_RATE) {
		fire_rate_counter += 1;
	} else if (!in_progress) {
		if (tick == 0) {
			random_column = rand () % 5;
		}
		if (invaders[starting_row][random_column] != SET) {
			if (starting_row != 0) {
				starting_row -= 1;
				tick = 1;
			} else {
				tick = 0;
			}
		} else {
			tick = 2;
		}
		if (tick == 2) {
			starting_row += 1;
			display_pixel_set (random_column, starting_row, 1);
			in_progress = 1;
			tick = 0;
		}
		fire_rate_counter = 0;
	} else {
		if (starting_row < 3) {
			if (invaders[starting_row][random_column] != SET) {
				display_pixel_set (random_column, starting_row, 0);
			}
			starting_row += 1;
			display_pixel_set (random_column, starting_row, 1);
		} else if (starting_row < 6) {
			display_pixel_set (random_column, starting_row, 0);
			starting_row += 1;
			display_pixel_set (random_column, starting_row, 1);
		} else {
			display_pixel_set (random_column, starting_row, 0);
			in_progress = 0;
			starting_row = 3;
			random_column = 0;
		}
		fire_rate_counter = 0;
	}

	enemy_fire_col = random_column;
	enemy_fire_row = starting_row;

	display_update ();
}
