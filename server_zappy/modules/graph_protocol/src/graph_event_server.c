/*
** graph_event_server.c for zappy in /home/gelin_g/Zappy/server_zappy/modules/graph_protocol
** 
** Made by guillaume gelin
** Login   <gelin_g@epitech.net>
** 
** Started on  Wed Jul  6 00:29:49 2011 guillaume gelin
** Last update Fri Jul  8 07:00:24 2011 ramnes
*/

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

  client = (t_fds *)data;
  sendf_all("pdi %d", player_data->id);
  return (true);
}

/* seg: ServerEnd */

bool	graph_seg(void *data)
{
  sendf_all("seg %s", (char*)data);
  return (true);
}

/* smg: ServerMsg */

bool	graph_smg(void *data)
{
  sendf_all("smg %s", (char*)data);
  return (true);
}

/*
** ppo: PlayerMove
** Basically, this is a cmd, but we override it with
** an event to send a ppo to all when a player moves.
*/

bool	graph_eppo(void *data)
{
  t_fds	*client;
  unsigned int	x;
  unsigned int	y;
  unsigned int	o;

  client = (t_fds *)data;
  get_player_pos(player_data->id, &x, &y, &o);
  sendf_all("ppo %d %d %d %d", player_data->id, x, y, o);
  return (true); 
}
