/*
** graph_event_player.c for zappy project
** 
** Made by ramnes
** <perso@ramnes.eu>
** 
** Started on  Wed Jul  6 16:43:06 2011 by ramnes
** Last update Fri Jul  8 07:07:50 2011 ramnes
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
	    ((t_bdata *)data)->ui1,
	    ((t_bdata *)data)->txt1);
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
  (void)data;
  sendf_all("pdr %d %d",
	    ((t_bdata *)data)->ui1,
	    ((t_bdata *)data)->ui2);
  return (true);
}

/* pgt: TakeItem */

bool	graph_pgt(void *data)
{
  (void)data;
  sendf_all("pgt %d %d",
	    ((t_bdata *)data)->ui1,
	    ((t_bdata *)data)->ui2);
  return (true);
}
