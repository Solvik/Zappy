/*
** gserv_set_box_delplayer.c for Zappy in ./server_zappy/src
** 
** Made by di-mar_j
** Login   <di-mar_j@epitech.net>
** 
** Started on  Thu Jun 23 22:12:26 2011 di-mar_j
** Last update Sun Jul 10 23:15:49 2011 di-mar_j
*/

#include		<stdlib.h>
#include		"team.h"
#include		"tserver.h"

extern t_server		*gserv;

static bool		match_player(void *data, void *arg)
{
  return (data == arg);
}

void			set_box_delplayer(t_player *player)
{
  t_box 		*box;

  if (!player || !(box = get_box(player->x, player->y)))
    return ;
  del_node_as_arg(&box->players, match_player, player);
}

void			set_box_delplayer_coor(t_player *player, uint x, uint y)
{
  t_box 		*box;

  if (!player || !(box = get_box(x, y)))
    return ;
  del_node_as_arg(&box->players, match_player, player);
}

