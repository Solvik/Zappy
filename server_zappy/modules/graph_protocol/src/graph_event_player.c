/*
** graph_event_player.c for Zappy in ./server_zappy/modules/graph_protocol/src
** 
** Made by di-mar_j
** Login   <di-mar_j@epitech.net>
** 
** Started on  Thu Jun 23 22:12:26 2011 di-mar_j
** Last update Sun Jul 10 23:15:49 2011 di-mar_j
*/

#include <stdlib.h>
#include "tserver.h"
#include "graph_events.h"
#include "sends_all.h"
#include "player.h"

/* pex: Expulse */
bool	graph_pex(void *data)
{
  t_fds *client;

  client = (t_fds *)data;
  sendf_all("pex %d", player_data->id);
  return (true);
}

/* pbc: Broadcast */
bool	graph_pbc(void *data)
{
  sendf_all("pbc %d %s",
	    ((t_generic *)data)->ui1,
	    ((t_generic *)data)->txt1);
  return (true);
}

/* pfk: Fork */
bool	graph_pfk(void *data)
{
  t_player *p;
  t_egg	*egg;

  if (!(egg = (t_egg*)data) || !(p = (t_player*)egg->father))
    return (false);
  sendf_all("pfk %d", p->id);
  return (true);
}

/* pdr: DropItem */
bool	graph_pdr(void *data)
{
  fds	client;

  client = ((t_generic *)data)->client;
  sendf_all("pdr %d %d", player_data->id,
	    ((t_generic *)data)->ui1);
  return (true);
}

/* pgt: TakeItem */
bool	graph_pgt(void *data)
{
  fds	client;

  client = ((t_generic *)data)->client;
  sendf_all("pgt %d %d", player_data->id,
	    ((t_generic *)data)->ui1);
  return (true);
}
