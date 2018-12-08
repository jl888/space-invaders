/** 
 	@file navswitch_task.c
	@author GitHub @ jl888
	@date 08/10/2016
	@brief This module controls the user's position on the LED matrix by using the
	navswitch on the board.
*/

#include "system.h"
#include "display.h"
#include "navswitch.h"
#include "check_task.h"

#define NOT_FIRING -1

int fire_position = NOT_FIRING;     // -1 for not firing, otherwise it will be a column position
int cannon_position = 0;	// Position of the user
int navswitch_push = 0;

/*
	This function controls the user's position on the LED matrix by using the
 	navswitch. The user can select East to West for movement. North is to shoot and
 	Push to restart if the game is over.
*/
void navswitch_task (__unused__ void *data)
{	
	static int col_position = 2;
	display_pixel_set (col_position, 6, 1);		// Display the user's position at the beginning
	cannon_position = col_position;
	navswitch_update ();

	if (navswitch_push_event_p (NAVSWITCH_EAST)) { 
		if (col_position + 1 < 5) {
			display_pixel_set (col_position, 6, 0);
			col_position += 1;
		} 
	}
	if (navswitch_push_event_p (NAVSWITCH_WEST)) {
		if (col_position - 1 >= 0) {
			display_pixel_set (col_position, 6, 0);
			col_position -= 1;
		}
	}
	if (navswitch_push_event_p (NAVSWITCH_NORTH)) {
		if (fire_position == NOT_FIRING) {
			fire_position = col_position;
		}
	}
	if (navswitch_push_event_p (NAVSWITCH_PUSH) && game_over) {
		navswitch_push = 1;
	}

	display_update ();
}
