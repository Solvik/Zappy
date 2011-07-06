/*
** graph_event_global.c for zappy in /home/gelin_g/Zappy/server_zappy/modules/graph_protocol
** 
** Made by guillaume gelin
** Login   <gelin_g@epitech.net>
** 
** Started on  Wed Jul  6 00:29:49 2011 guillaume gelin
** Last update Wed Jul  6 16:44:28 2011 ramnes
*/

#define	_GNU_SOURCE

#include <stdio.h>
#include <stdlib.h>
#include "tserver.h"
#include "graph_events.h"
#include "sends_all.h"
#include "player.h"

/* pnw: Connexion d'un nouveau joueur */

bool   	graph_pnw(void *data)
{
  t_fds		*client;
  char		*to_send;

  client = (t_fds *)data;
  asprintf(&to_send, "pnw %d %d %d %d %d %s",
	   player_data->id,
	   player_data->x,
	   player_data->y,
	   ((uint)(player_data->direction)) + 1,
	   player_data->level,
	   get_team_of_player(player_data)->name);
  sends_all(to_send);
  free(to_send);
  return (true);
}

/* pex: Un joueur est expulsé */

bool	graph_pex(void *data)
{
  t_fds *client;
  char	*to_send;

  client = (t_fds *)data;
  asprintf(&to_send, "pex %d", player_data->id);
  sends_all(to_send);
  free(to_send);
  return (true);
}

/* pbc: Un joueur fait un broadcast */

bool	graph_pbc(void *data)
{
  char	*to_send;

  asprintf(&to_send, "pbc %d %s", ((t_bdata *)data)->id, ((t_bdata *)data)->msg);
  sends_all(to_send);
  free(((t_bdata *)data)->msg);
  free(data);
  free(to_send);
  return (true);
}
