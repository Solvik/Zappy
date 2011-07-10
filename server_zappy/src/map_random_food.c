/*
** map_random_food.c for Zappy in ./server_zappy/src
** 
** Made by di-mar_j
** Login   <di-mar_j@epitech.net>
** 
** Started on  Thu Jun 23 22:12:26 2011 di-mar_j
** Last update Sun Jul 10 23:15:49 2011 di-mar_j
*/

#include	<stdlib.h>
#include	"tserver.h"
#include	"conf.h"

void		map_random_food(void)
{
  set_box_addfood(rand() % get_map_width(),
		  rand() % get_map_height(),
		  rand() % map_nb_food);
}
