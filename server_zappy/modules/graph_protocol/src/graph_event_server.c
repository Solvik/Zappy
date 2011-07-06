/*
** graph_event_server.c for zappy in /home/gelin_g/Zappy/server_zappy/modules/graph_protocol
** 
** Made by guillaume gelin
** Login   <gelin_g@epitech.net>
** 
** Started on  Wed Jul  6 00:29:49 2011 guillaume gelin
** Last update Wed Jul  6 20:03:29 2011 ramnes
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
  if (asprintf(&to_send, "pnw %d %d %d %d %d %s",
	       player_data->id,
	       player_data->x,
	       player_data->y,
	       ((uint)(player_data->direction)) + 1,
	       player_data->level,
	       get_team_of_player(player_data)->name) == -1)
    return (false);
  sends_all(to_send);
  free(to_send);
  return (true);
}

/* pdi: Le joueur est mort de faim */

bool	graph_pdi(void *data)
{
  t_fds *client;
  char	*to_send;

  client = (t_fds *)data;
  if (asprintf(&to_send, "pdi %d", player_data->id) == -1)
    return (false);
  sends_all(to_send);
  free(to_send);
  return (true);
}

/* seg: Game Over */

bool	graph_seg(void *data)
{
  char	*to_send;

  if (asprintf(&to_send, "seg %s", (char*)data) == -1)
    return (false);
  sends_all(to_send);
  free(to_send);
  return (true);
}

/* smg: Message du serveur */

bool	graph_smg(void *data)
{
  char	*to_send;

  if (asprintf(&to_send, "smg %s", (char*)data) == -1)
    return (false);
  sends_all(to_send);
  free(to_send);
  return (true);
}
