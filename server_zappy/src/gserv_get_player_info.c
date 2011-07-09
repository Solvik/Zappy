/*
** gserv_get_player_info.c for  in /home/solvik/tek2/proj/Zappy
**
** Made by solvik blum
** Login   <blum_s@epitech.net>
**
** Started on  Sat Jul  9 18:39:47 2011 solvik blum
** Last update Sat Jul  9 18:39:57 2011 solvik blum
*/

#include		<stdlib.h>
#include		"tserver.h"

uint			get_player_level(uint id)
{
  t_player *	player;

  if ((player = get_player_by_id(id)) == NULL)
    return (0);
  return (player->level);
}

bool			get_player_pos(uint id, uint * x, uint * y, uint * o)
{
  t_player *	player;

  if ((player = get_player_by_id(id)) == NULL)
    return (false);
  if (x != NULL)
    *x = player->x;
  if (y != NULL)
    *y = player->y;
  if (o != NULL)
    *o = ((uint)player->direction) + 1;
  return (true);
}

t_list *		get_player_stones(uint id)
{
  t_player *		player;

  if (!(player = get_player_by_id(id)))
    return (NULL);
  return (player->stones);
}

uint			get_player_food(uint id)
{
  t_player *		player;

  if (!(player = get_player_by_id(id)))
    return (0);
  return (player->food);
}

