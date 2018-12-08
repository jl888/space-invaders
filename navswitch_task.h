/** 
 	@file navswitch_task.c
	@author GitHub @ jl888
	@date 08/10/2016
	@brief This module controls the user's position on the LED matrix by using the
	navswitch on the board.
*/

#ifndef NAVSWITCH_TASK_H
#define NAVSWITCH_TASK_H

#include "system.h"

extern int fire_position;	// -1 for not firing, otherwise it will be a column position
extern int cannon_position;	// Position of the user
extern int navswitch_push;	// 1 if the navsiwtch has been push, 0 otherwise

/*
	This function controls the user's position on the LED matrix by using the
 	navswitch. The user can select East to West for movement. North is to shoot and
 	Push to restart if the game is over.
*/
void navswitch_task (__unused__ void *data);

#endif
