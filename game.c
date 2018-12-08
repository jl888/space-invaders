/**
	@file game.c
	@author GitHub @ jl888
	@date 03/10/2016
	@brief This program is my take on the game, Space Invaders.
	Note: This program designed for a custom made Embedded System.
*/

#include <stdlib.h>
#include "task.h"
#include "system.h"
#include "display.h"
#include "navswitch.h"
#include "led.h"
#include "tinygl.h"
#include "../fonts/font5x7_1.h"
#include "display_aliens_task.h"
#include "navswitch_task.h"
#include "user_fire_task.h"
#include "alien_fire_task.h"
#include "check_task.h"

#define DISPLAY_TASK_RATE 500
#define NAVSWITCH_TASK_RATE 300
#define FIRE_TASK_RATE 300
#define ALIEN_FIRE_TASK_RATE 300
#define LOOP_RATE 500
#define CHECK_TASK_RATE 500

/** This functions brings the game together by combining all the modules and drivers. */
int main (void)
{
	task_t tasks[] =
	{
		{.func = display_aliens_task, .period = TASK_RATE / DISPLAY_TASK_RATE},
		{.func = navswitch_task, .period = TASK_RATE / NAVSWITCH_TASK_RATE},
		{.func = user_fire_task, .period = TASK_RATE / FIRE_TASK_RATE},
		{.func = alien_fire_task, .period = TASK_RATE / ALIEN_FIRE_TASK_RATE},
		{.func = check_task, .period = TASK_RATE / CHECK_TASK_RATE},
	};
	
	system_init ();
	display_init ();
	navswitch_init ();
	led_init ();
	led_set (LED1, 0);
	tinygl_init (LOOP_RATE);
	tinygl_font_set (&font5x7_1);
	tinygl_text_mode_set (TINYGL_TEXT_MODE_SCROLL);
	tinygl_text_speed_set (7);
	task_schedule (tasks, ARRAY_SIZE (tasks));
	return 0;
}
