/*
** graph_graphic.c for  in /home/seb/git/Zappy/server_zappy/modules/graph_protocol
**
** Made by seb
** Login   <seb@epitech.net>
**
** Started on  Tue Jun 28 15:12:30 2011 seb
** Last update Fri Jul  8 03:27:24 2011 ramnes
*/

#define _GNU_SOURCE

#include <stdio.h>
#include <stdlib.h>
#include "tserver.h"
#include "player.h"
#include "graph_graphic.h"
#include "graph_map.h"
#include "graph_team.h"
#include "graph_time.h"
#include "graph_events.h"

static void	_pnw(void *data, void *dest)
{
  t_fds		*client;
  char		*to_send;

  client = (t_fds *)data;
  if (asprintf(&to_send, "pnw %d %d %d %d %d %s",
	       player_data->id,
	       player_data->x,
	       player_data->y,
	       ((uint)(player_data->direction)) + 1,
	       player_data->level,
	       get_team_of_player(player_data)->name) == -1)
    return;
  sends(dest, to_send);
  free(to_send);
}

/*
**   //graph_enw(client, NULL); - l: 24
*/

bool graph_graphic(t_fds *client, char *cmd __attribute__((unused)))
{
  t_module	*mod;

  mod = get_module_by_name("Zappy Protocol");
  graph_sgt(client, NULL);
  graph_msz(client, NULL);
  graph_mct(client, NULL);
  graph_tna(client, NULL);
  foreach_arg_list(mod->clients, _pnw, client);
  return (true);
}
