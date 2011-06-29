/*
** voir.c for  in /home/solvik/tek2/proj/Zappy/server_zappy/src
**
** Made by solvik blum
** Login   <blum_s@epitech.net>
**
** Started on  Mon Jun 13 12:46:13 2011 solvik blum
** Last update Wed Jun 29 12:20:56 2011 solvik blum
*/

#include <stdio.h>
#include <stdlib.h>

#include "player.h"
#include "server_zappy.h"



static const char	*enum_to_dir[4] =
  {
    "NORTH",
    "EAST",
    "SOUTH",
    "WEST",
  };

int		zappy_expulse(t_fds *client, char *cmd)
{
  t_list	*list;

  (void)cmd;
  list = get_players_at(player_data->x, player_data->y);
  if (get_list_len(list))
    {
      char	*ret;

      asprintf(&ret, "deplacement %s\n", enum_to_dir[player_data->direction]);
      sends(client, ret);
      sends(client, "ok\n");
    }
  else
    sends(client, "ko\n");
  return (1);
}
