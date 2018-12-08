/**
  @file user_fire_task.c
  @author GitHub @ jl888
  @date 08/10/2016
  @brief This module enables the users to shoot the aliens, one at a time.
*/

#ifndef USER_FIRE_TASK_H
#define USER_FIRE_TASK_H

#include "system.h"

extern int winner_count;	// Counts the number of aliens that has been shot

/*
	This function checks if the user has fire a shot at an alien. A firing animation will be
	diplayed on the LED matrix if it has.
*/
void user_fire_task (__unused__ void *data);

#endif
