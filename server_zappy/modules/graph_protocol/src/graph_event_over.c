/*
** graph_event_over.c for zappy in /home/gelin_g/Zappy/server_zappy/modules/graph_protocol
** 
** Made by guillaume gelin
** Login   <gelin_g@epitech.net>
** 
** Started on  Sat Jul  9 23:55:39 2011 guillaume gelin
** Last update Sun Jul 10 21:05:35 2011 guillaume gelin
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
