/** 
  @file display_aliens_task.h
  @author GitHub @ jl888
  @date 08/10/2016
  @brief This module is used to display the aliens on the LED matrix.
*/

#ifndef DISPLAY_ALIENS_TASK_H
#define DISPLAY_ALIENS_TASK_H

#include "system.h"
#include "display.h"

extern int invaders_row;  // Row currently selected in the invaders array
extern int invaders_col;  // Column currently selected in the invaders array

extern int invaders[3][5];


/*
  Displays the aliens on the LED matrix. Otherwise, resets the LED matrix if
  all the aliens are dead.
*/
void display_aliens_task (__unused__ void *data);

#endif
