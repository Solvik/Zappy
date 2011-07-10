/*
** gserv_set_player_delfood.c for  in /home/solvik/tek2/proj/Zappy
**
** Made by solvik blum
** Login   <blum_s@epitech.net>
**
** Started on  Sat Jul  9 18:39:30 2011 solvik blum
** Last update Sat Jul  9 18:39:30 2011 solvik blum
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
