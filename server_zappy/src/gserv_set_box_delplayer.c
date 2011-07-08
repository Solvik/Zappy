/*
** gserv_del_player.c for  in /Users/Lifely/Developer/project/Zappy/server_zappy
** 
** Made by Julien Di Marco
** Login   <Lifely@epitech.net>
** 
** Started on  Thu Jun 30 05:05:43 2011 Julien Di Marco
** Last update Thu Jun 30 05:05:43 2011 Julien Di Marco
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

