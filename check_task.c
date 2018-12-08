/** 
 	@file check_task.c
	@author GitHub @ jl888
	@date 08/10/2016
	@brief This module checks if the user has been shot (then game over) or if all the aliens
  are all shot (then you win).
*/

#include "system.h"
#include "led.h"
#include "tinygl.h"
#include "../fonts/font5x7_1.h"
#include "navswitch_task.h"
#include "display_aliens_task.h"
#include "alien_fire_task.h"
#include "user_fire_task.h"

#define TOTAL_ALIENS 15
#define USER_ROW 6

int game_over = 0;

/* 
	This function checks if the game is over (the user has lost) or if all the
 	aliens have been shot (the user has won). It will then display the relevant text to
 	inform the user.
 */
void check_task (__unused__ void *data) 
{
	static int tick = 0;
	static int row = 0;
	static int col = 0;

	if (cannon_position == enemy_fire_col && enemy_fire_row == USER_ROW && !game_over) {
		game_over = 1;
		tinygl_text ("GAME_OVER");
	} else if (winner_count >= TOTAL_ALIENS && !game_over) {
		game_over = 1;
		tinygl_text ("WINNER");
		led_set (LED1, 1);
	} 
	
	if (game_over && navswitch_push) {	// Begin resetting the values in the array
		tinygl_clear ();
		display_clear ();
		navswitch_push = 0;
		invaders[row][col] = 0;
		invaders_col = col;
		invaders_row = row;
		col += 1;
		game_over = 0;
		cannon_position = 0;
		fire_position = -1;
		enemy_fire_col = 0;
		enemy_fire_row = 0;
		tick += 1;	// Begin ticking until all the values in the array are set to 0
	} else if (tick > 0) {
		if (row < 3) {
			invaders[row][col] = 0;
			invaders_col = col;
			invaders_row = row;
			tick += 1;
			if (col < 4) {
				col += 1;
			} else {
				row += 1;
				col = 0;
			}
		} 
		if (tick > TOTAL_ALIENS - 1) {
			tick = 0;
			led_set (LED1, 0);
			col = 0;
			row = 0;
			winner_count = 0;
		}
	}

	tinygl_update ();
}
