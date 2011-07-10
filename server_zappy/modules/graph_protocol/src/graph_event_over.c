/*
** graph_event_over.c for Zappy in ./server_zappy/modules/graph_protocol/src
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

/* eppo: PlayerMove */
bool	graph_eppo(void *data)
{
  t_fds	*client;
  uint	x;
  uint	y;
  uint	o;

  client = (t_fds *)data;
  get_player_pos(player_data->id, &x, &y, &o);
  sendf_all("ppo %d %d %d %d", player_data->id, x, y, o);
  return (true);
}

/* ebct: TakeItem/DropItem */
bool	graph_ebct(void *data)
{
  t_fds	*client;

  client = ((t_generic *)data)->client;
  sendf_all("bct %d %d %d %d %d %d %d %d %d",
	player_data->x, player_data->y,
	get_box_nbfood(player_data->x, player_data->y),
	get_box_nbstones(player_data->x, player_data->y, LINEMATE),
	get_box_nbstones(player_data->x, player_data->y, DERAUMERE),
	get_box_nbstones(player_data->x, player_data->y, SIBUR),
	get_box_nbstones(player_data->x, player_data->y, MENDIANE),
	get_box_nbstones(player_data->x, player_data->y, PHIRAS),
	get_box_nbstones(player_data->x, player_data->y, THYSTAME));
  return (true);
}

/* epin: TakeItem/DropItem */
bool	graph_epin(void *data)
{
  t_fds *client;

  client = ((t_generic *)data)->client;
  sendf_all("pin %d %d %d %d %d %d %d %d %d %d",
	player_data->id, player_data->x, player_data->y,
	get_player_food(player_data->id),
	get_player_nbstones(player_data->id, LINEMATE),
	get_player_nbstones(player_data->id, DERAUMERE),
	get_player_nbstones(player_data->id, SIBUR),
	get_player_nbstones(player_data->id, MENDIANE),
	get_player_nbstones(player_data->id, PHIRAS),
	get_player_nbstones(player_data->id, THYSTAME));
  return (true);
}

/* eplv: IncaEnd */
bool	graph_eplv(void *data)
{
  t_fds *client;

  client = (t_fds *)data;
  sendf_all("plv %d %d", player_data->id, player_data->level);
  return (true);
}
