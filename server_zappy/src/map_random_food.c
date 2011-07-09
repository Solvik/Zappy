/*
** map_random_food.c for  in /home/solvik/tek2/proj/Zappy/server_zappy
**
** Made by solvik blum
** Login   <blum_s@epitech.net>
**
** Started on  Sat Jul  9 18:41:14 2011 solvik blum
** Last update Sat Jul  9 18:41:15 2011 solvik blum
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
