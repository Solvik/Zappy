/*
** gserv_set_box_addplayer.c for Zappy in ./server_zappy/src
** 
** Made by di-mar_j
** Login   <di-mar_j@epitech.net>
** 
** Started on  Thu Jun 23 22:12:26 2011 di-mar_j
** Last update Sun Jul 10 23:15:49 2011 di-mar_j
*/

#include		<stdlib.h>
#include		<string.h>
#include		"tserver.h"
#include		"player.h"
#include		"team.h"
#include		"server_zappy.h"

extern t_server 	*gserv;

bool		set_box_addplayer(t_player *player, uint x, uint y)
{
  t_box		*box;

  if (!player || !(box = get_box(x, y)) ||
      !put_in_list(&box->players, player))
    return (false);
  return (true);
}
