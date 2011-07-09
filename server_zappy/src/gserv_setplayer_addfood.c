/*
** gserv_setplayer_addfood.c for  in /home/solvik/tek2/proj/Zappy/server_zappy
**
** Made by solvik blum
** Login   <blum_s@epitech.net>
**
** Started on  Sat Jul  9 18:27:08 2011 solvik blum
** Last update Sat Jul  9 18:27:08 2011 solvik blum
*/

#include		<stdlib.h>
#include		"tserver.h"

bool			setplayer_addfood(uint id, uint nb)
{
  t_player *		player;

  if (!(player = get_player_by_id(id)))
    return (false);
  player->food += nb;
  return (true);
}
