/*
** set_player_delstone.c for  in /home/solvik/tek2/proj/Zappy/server_zappy/src
**
** Made by solvik blum
** Login   <blum_s@epitech.net>
**
** Started on  Sun Jul  3 16:30:15 2011 solvik blum
** Last update Sun Jul  3 16:33:14 2011 solvik blum
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

uint			set_player_delstone(t_player *player, e_stone type,
					   uint nb)
{
  t_stone 		*stone;
  uint			tmp;

  if (!(stone = get_data_as_arg(player->stones, match_stone, &type)))
    return (0);
  if ((tmp = stone->nb) < nb)
    {
      stone->nb = 0;
      return (tmp);
    }
  stone->nb -= nb;
  return (nb);
}
