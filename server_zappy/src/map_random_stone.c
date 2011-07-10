/*
** map_random_stone.c for Zappy in ./server_zappy/src
** 
** Made by di-mar_j
** Login   <di-mar_j@epitech.net>
** 
** Started on  Thu Jun 23 22:12:26 2011 di-mar_j
** Last update Sun Jul 10 23:15:49 2011 di-mar_j
*/

#include	<stdlib.h>
#include	<stdio.h>

#include	"tserver.h"
#include	"stone.h"
#include	"conf.h"

static const e_stone stonetab[] =
  {
    LINEMATE,
    DERAUMERE,
    SIBUR,
    MENDIANE,
    PHIRAS,
    THYSTAME
  };

void		map_random_stone(void)
{
  static size_t	i = 0;

  set_box_addstone(rand() % get_map_width(),
		   rand() % get_map_height(),
		   stonetab[i++],
		   rand() % map_nb_stones);
  i = (i < (sizeof(stonetab) / sizeof(*stonetab)) ? i : 0);
}
