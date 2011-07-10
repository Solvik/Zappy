/*
** gserv_get_box_nbstones_by_player.c for  in /home/solvik/tek2/proj/Zappy/server_zappy/src
**
** Made by solvik blum
** Login   <blum_s@epitech.net>
**
** Started on  Mon Jul  4 01:14:16 2011 solvik blum
** Last update Mon Jul  4 01:20:29 2011 solvik blum
*/

#include		<stdlib.h>

#include		"stone.h"
#include		"tserver.h"
#include		"server_zappy.h"

extern t_server 	*gserv;

static bool		match_stone(void *data, void *stone)
{
  return (((t_stone *)data)->type == *((e_stone *)stone));
}

uint			get_box_nbstones_by_player(t_player *player,
						   e_stone type)
{
  t_stone		*stone;

  if (!(stone = get_data_as_arg(player->stones, match_stone, &type)))
    return (0);
  return (stone->nb);
}
