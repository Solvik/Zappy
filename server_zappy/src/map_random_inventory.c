/*
** map_random_inventory.c for Zappy in ./server_zappy/src
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
#include	"conf.h"

void		map_random_fill_stones(void)
{
   size_t	i;

  i = 0;
  while (i++ < (((double)map_stones_density / 100.0) * (double)get_map_max()))
    map_random_stone();
}

void		map_random_fill_food(void)
{
  size_t	i;

  i = 0;
  while (i++ < (((double)map_food_density / 100.0) * (double)get_map_max()))
    map_random_food();
}

void		map_random_fill(void)
{
  map_random_fill_stones();
  map_random_fill_food();
}
