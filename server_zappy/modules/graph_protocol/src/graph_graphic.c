/*
** graph_graphic.c for  in /home/seb/git/Zappy/server_zappy/modules/graph_protocol
**
** Made by seb
** Login   <seb@epitech.net>
**
** Started on  Tue Jun 28 15:12:30 2011 seb
** Last update Sun Jul 10 02:07:54 2011 guillaume gelin
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

  egg = (t_egg *)data;
  sendf(dest, "enw %d %d %d %d", egg->id, egg->father->id, egg->x, egg->y);
}

/*
**   //graph_enw(client, NULL); - l: 24
*/

bool graph_graphic(t_fds *client, char *cmd __attribute__((unused)))
{
  t_module	*mod;
  t_list	*eggs;

  mod = get_module_by_name("Zappy Protocol");
  eggs = get_eggs();
  graph_sgt(client, NULL);
  graph_msz(client, NULL);
  graph_mct(client, NULL);
  graph_tna(client, NULL);
  foreach_arg_list(mod->clients, _pnw, client);
  foreach_arg_list(eggs, _enw, client);
  return (true);
}
