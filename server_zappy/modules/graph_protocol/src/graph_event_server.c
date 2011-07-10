/*
** graph_event_server.c for Zappy in ./server_zappy/modules/graph_protocol/src
** 
** Made by di-mar_j
** Login   <di-mar_j@epitech.net>
** 
** Started on  Thu Jun 23 22:12:26 2011 di-mar_j
** Last update Sun Jul 10 23:15:49 2011 di-mar_j
*/

#include "tserver.h"
#include "graph_events.h"
#include "sends_all.h"
#include "player.h"

/* pnw: PlayerNew */
bool   	graph_pnw(void *data)
{
  t_fds	*client;

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
  sendf_all("pdi %d", ((t_player *)data)->id);
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
