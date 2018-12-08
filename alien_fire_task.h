/** 
  @file alien_fire_task.h
  @author GitHub @ jl888
  @date 08/10/2016
  @brief This module uses a random number generator to select a column within the grid.
  The alien first in line will be used for shooting.
*/

#ifndef ALIEN_FIRE_TASK_H
#define ALIEN_FIRE_TASK_H

#include "system.h"

extern int enemy_fire_row;		// Tracking the row location of the missile
extern int enemy_fire_col;		// Tracking the col location of the missile

/** This function randomly selects an alien to shoot from in a random column 
 * where at least 1 alien is still alive. */
void alien_fire_task (__unused__ void *data);

#endif
