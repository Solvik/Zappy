/*
** gserv_set_player_delfood.c for Zappy in ./server_zappy/src
** 
** Made by di-mar_j
** Login   <di-mar_j@epitech.net>
** 
** Started on  Thu Jun 23 22:12:26 2011 di-mar_j
** Last update Sun Jul 10 23:15:49 2011 di-mar_j
*/

#include		<stdlib.h>
#include		"tserver.h"

uint			set_player_delfood(uint id, uint nb)
{
  t_player *		player;
  uint			tmp;

  if (!(player = get_player_by_id(id)))
    return (0);
  if ((tmp = player->food) < nb)
    {
      player->food = 0;
      return (tmp);
    }
  player->food -= nb;
  return (nb);
}
