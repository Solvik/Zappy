/*
** graph_event_player.c for zappy project
**
** Made by ramnes
** <perso@ramnes.eu>
**
** Started on  Wed Jul  6 16:43:06 2011 by ramnes
** Last update Sat Jul  9 18:43:55 2011 solvik blum
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
  t_fds *client;

  client = (t_fds *)data;
  sendf_all("pfk %d", player_data->id);
  return (true);
}

/* pdr: DropItem */
bool	graph_pdr(void *data)
{
  sendf_all("pdr %d %d",
	    ((t_generic *)data)->ui1,
	    ((t_generic *)data)->ui2);
  return (true);
}

/* pgt: TakeItem */
bool	graph_pgt(void *data)
{
  sendf_all("pgt %d %d",
	    ((t_generic *)data)->ui1,
	    ((t_generic *)data)->ui2);
  return (true);
}
