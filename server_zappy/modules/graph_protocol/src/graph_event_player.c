/*
** graph_event_player.c for zappy project
** 
** Made by ramnes
** <perso@ramnes.eu>
** 
** Started on  Wed Jul  6 16:43:06 2011 by ramnes
** Last update Thu Jul  7 20:26:47 2011 ramnes
*/

#define	_GNU_SOURCE

#include <stdio.h>
#include <stdlib.h>
#include "tserver.h"
#include "graph_events.h"
#include "sends_all.h"
#include "player.h"

/* pex: KickAss */

bool	graph_pex(void *data)
{
  t_fds *client;
  char	*to_send;

  client = (t_fds *)data;
  if (asprintf(&to_send, "pex %d", player_data->id) == -1)
    return (false);
  sends_all(to_send);
  free(to_send);
  return (true);
}

/* pbc: Broadcast */

bool	graph_pbc(void *data)
{
  char	*to_send;

  if (asprintf(&to_send, "pbc %d %s",
	       ((t_bdata *)data)->ui1,
	       ((t_bdata *)data)->txt1) == -1)
    return (false);
  sends_all(to_send);
  free(((t_bdata *)data)->txt1);
  free(data);
  free(to_send);
  return (true);
}

/* pfk: NewEgg */

bool	graph_pfk(void *data)
{
  t_fds *client;
  char	*to_send;

  client = (t_fds *)data;
  if (asprintf(&to_send, "pfk %d", player_data->id) == -1)
    return (false);
  sends_all(to_send);
  free(to_send);
  return (true);
}

/* pdr: DropItem */

bool	graph_pdr(void *data)
{
  char	*to_send;

  (void)data;
  if (asprintf(&to_send, "pdr %d %d",
	       0 /* id */,
	       42 /* numero de ressource */) == -1)
    return (false);
  sends_all(to_send);
  free(to_send);
  return (true);
}

/* pgt: TakeItem */

bool	graph_pgt(void *data)
{
  char	*to_send;

  (void)data;
  if (asprintf(&to_send, "pgt %d %d",
	       0 /* id */,
	       42 /* numero de ressource */) == -1)
    return (false);
  sends_all(to_send);
  free(to_send);
  return (true);
}
