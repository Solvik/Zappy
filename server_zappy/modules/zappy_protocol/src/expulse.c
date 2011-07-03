/*
** voir.c for  in /home/solvik/tek2/proj/Zappy/server_zappy/src
**
** Made by solvik blum
** Login   <blum_s@epitech.net>
**
** Started on  Mon Jun 13 12:46:13 2011 solvik blum
** Last update Sun Jul  3 17:25:05 2011 solvik blum
*/

#define _GNU_SOURCE

#include <stdio.h>
#include <stdlib.h>
#include <stdio.h>

#include "player.h"
#include "server_zappy.h"
#include "tserver.h"

static const char	*enum_to_dir[4] =
  {
    "NORTH",
    "EAST",
    "SOUTH",
    "WEST",
  };

int		zappy_expulse(t_fds *client, char *cmd)
{
  int		r;
  char		*ret;
  t_list	*list;

  (void)cmd;
  list = get_players(player_data->x, player_data->y);
  if (get_list_len(list))
    {
      r = asprintf(&ret, "deplacement %s", enum_to_dir[player_data->direction]);
      sends(client, ret);
      if (ret)
	free(ret);
      sends(client, "ok");
    }
  else
    sends(client, "ko");
  return (1);
}
