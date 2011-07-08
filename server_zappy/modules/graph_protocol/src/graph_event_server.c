/*
** graph_event_server.c for zappy in /home/gelin_g/Zappy/server_zappy/modules/graph_protocol
** 
** Made by guillaume gelin
** Login   <gelin_g@epitech.net>
** 
** Started on  Wed Jul  6 00:29:49 2011 guillaume gelin
** Last update Fri Jul  8 06:49:59 2011 ramnes
*/

#define	_GNU_SOURCE

#include <stdio.h>
#include <stdlib.h>
#include "tserver.h"
#include "graph_events.h"
#include "sends_all.h"
#include "player.h"

/* pnw: PlayerNew */

bool   	graph_pnw(void *data)
{
  t_fds		*client;

  client = (t_fds *)data;
  sendf_all("pnw %d %d %d %d %d %s",
	    player_data->id,
	    player_data->x,
	    player_data->y,
	    ((uint)(player_data->direction)) + 1,
	    player_data->level,
	    get_team_of_player(player_data)->name);
  return (true);
}

/* pdi: PlayerDied */

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

/* seg: ServerEnd */

bool	graph_seg(void *data)
{
  char	*to_send;

  if (asprintf(&to_send, "seg %s", (char*)data) == -1)
    return (false);
  sends_all(to_send);
  free(to_send);
  return (true);
}

/* smg: ServerMsg */

bool	graph_smg(void *data)
{
  char	*to_send;

  if (asprintf(&to_send, "smg %s", (char*)data) == -1)
    return (false);
  sends_all(to_send);
  free(to_send);
  return (true);
}

/* ppo: PlayerMove */
/* Basically, this is a cmd, but we override it with */
/* an event to send a ppo to all when a player moves. */

bool	graph_eppo(void *data)
{
  t_fds	*client;
  char	*to_send;
  unsigned int	x;
  unsigned int	y;
  unsigned int	o;

  client = (t_fds *)data;
  get_player_pos(player_data->id, &x, &y, &o);
  if (asprintf(&to_send, "ppo %d %d %d %d",
	       player_data->id, x, y, o) == -1)
    return (false);
  sends_all(to_send);
  return (true); 
}
