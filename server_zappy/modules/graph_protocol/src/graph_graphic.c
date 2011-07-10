/*
** graph_graphic.c for  in /home/seb/git/Zappy/server_zappy/modules/graph_protocol
**
** Made by seb
** Login   <seb@epitech.net>
**
** Started on  Tue Jun 28 15:12:30 2011 seb
** Last update Sun Jul 10 20:02:10 2011 guillaume gelin
*/

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

  client = (t_fds *)data;
  sendf(dest, "pnw %d %d %d %d %d %s",
	player_data->id,
	player_data->x,
	player_data->y,
	((uint)(player_data->direction)) + 1,
	player_data->level,
	get_team_of_player(player_data)->name);
}

static void	_enw(void *data, void *dest)
{
  t_egg		*egg;

  if ((egg = (t_egg *)data) && dest)
    sendf(dest, "enw %d %d %d %d", egg->id, egg->idf, egg->x, egg->y);
}

bool graph_graphic(t_fds *client, char *_)
{
  t_module	*mod;
  t_list	*eggs;

  (void)_;
  mod = get_module_by_name("Zappy Protocol");
  eggs = get_eggs();
  graph_msz(client, NULL);
  graph_sgt(client, NULL);
  graph_mct(client, NULL);
  graph_tna(client, NULL);
  foreach_arg_list(mod->clients, _pnw, client);
  foreach_arg_list(eggs, _enw, client);
  return (true);
}
