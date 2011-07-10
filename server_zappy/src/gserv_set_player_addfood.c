/*
** gserv_set_player_addfood.c for Zappy in ./server_zappy/src
** 
** Made by di-mar_j
** Login   <di-mar_j@epitech.net>
** 
** Started on  Thu Jun 23 22:12:26 2011 di-mar_j
** Last update Sun Jul 10 23:15:49 2011 di-mar_j
*/

#include		<stdlib.h>
#include		"tserver.h"

bool			set_player_addfood(uint id, uint nb)
{
  t_player *		player;

  if (!(player = get_player_by_id(id)))
    return (false);
  player->food += nb;
  return (true);
}
