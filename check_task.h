/* 
  @file check_task.h
  @author GitHub @ jl888
  @date 08/10/2016
  @brief This module checks if the user has been shot (then game over) or if all the aliens
  are all shot (then you win).
*/

#ifndef CHECK_TASK_H
#define CHECK_TASK_H

#include "system.h"

extern int game_over;

/* 
	This function checks if the game is over (the user has lost) or if all the
 	aliens have been shot (the user has won). It will then display the relevant text to
 	inform the user.
 */
void check_task (__unused__ void *data); 

#endif
