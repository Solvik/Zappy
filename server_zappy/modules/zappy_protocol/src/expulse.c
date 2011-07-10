/*
** voir.c for  in /home/solvik/tek2/proj/Zappy/server_zappy/src
**
** Made by solvik blum
** Login   <blum_s@epitech.net>
**
** Started on  Mon Jun 13 12:46:13 2011 solvik blum
** Last update Sat Jul  9 18:43:54 2011 ramnes
*/

#define _GNU_SOURCE

#include <stdio.h>
#include <stdlib.h>
#include <stdio.h>

#include "napi.h"

static const char	*enum_to_dir[4] =
  {
    "NORTH",
    "EAST",
    "SOUTH",
    "WEST",
  };

static void	expulse_players(void *data, void *dest)
{
  t_fds		*client;

  client = (t_fds *)data;
  if (player_data != (t_player *)dest)
    sends(data, "avance");
}

int		zappy_expulse(t_fds *client, char *cmd)
{
  int		r;
  char		*ret;
  t_list	*list;
  t_module      *mod;

  (void)cmd;
  list = get_box_players(player_data->x, player_data->y);
  if (get_list_len(list))
    {      
      mod = get_module_by_name("Zappy Protocol");
      foreach_arg_list(mod->clients, expulse_players, player_data);
      r = asprintf(&ret, "deplacement %s",
		   enum_to_dir[player_data->direction]);
      sends(client, ret);
      if (ret)
	free(ret);
      sends(client, "ok");
      event_relative_dispatch("Expulse", client, 0);
    }
  else
    sends(client, "ko");
  return (1);
}
