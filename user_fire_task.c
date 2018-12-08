/** 
 	@file user_fire_task.c
	@author GitHub @ jl888
	@date 08/10/2016
	@brief This module enables the users to shoot the aliens, one at a time.
*/

#include "system.h"
#include "navswitch_task.h"
#include "display_aliens_task.h"

#define USER_FIRE_RATE 70
#define NOT_FIRING -1
#define ALIEN_DEAD -1
#define SET 1

int winner_count = 0;	// Counts the number of aliens that has been shot

/*
	This function checks if the user has fire a shot at an alien. A firing animation will be
	diplayed on the LED matrix if it has.
*/
void user_fire_task (__unused__ void *data)
{	
	static int tick = 0;
	static int start_col_position = 5;
	
	if (tick < USER_FIRE_RATE) {
		tick += 1;
	} else if (fire_position != NOT_FIRING) {
		if (start_col_position == 5) {
			display_pixel_set (fire_position, start_col_position, 1);
			start_col_position -= 1;
		} else if (start_col_position < 5 && start_col_position > 2) {
			display_pixel_set (fire_position, start_col_position + 1, 0);
			display_pixel_set (fire_position, start_col_position, 1);
			start_col_position -= 1;
		} else if (start_col_position < 3) {
			if (start_col_position < 0) {
				display_pixel_set (fire_position, start_col_position + 1, 0);
				start_col_position = 5;
				fire_position = NOT_FIRING;
			}
			else if (invaders[start_col_position][fire_position] == SET) {
				display_pixel_set (fire_position, start_col_position + 1, 0);
				display_pixel_set (fire_position, start_col_position, 0);
				invaders[start_col_position][fire_position] = ALIEN_DEAD;
				winner_count += 1;
				start_col_position = 5;
				fire_position = NOT_FIRING;
			} else {
				display_pixel_set (fire_position, start_col_position + 1, 0);
				display_pixel_set (fire_position, start_col_position, 1);
				start_col_position -= 1;
			}
		}
		tick = 0;
	}

	display_update ();
}
