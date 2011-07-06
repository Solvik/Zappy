/*
** graph_event_player.c for zappy project
** 
** Made by ramnes
** <perso@ramnes.eu>
** 
** Started on  Wed Jul  6 16:43:06 2011 by ramnes
** Last update Wed Jul  6 20:24:26 2011 ramnes
*/

#define	_GNU_SOURCE

#include <stdio.h>
#include <stdlib.h>
#include "tserver.h"
#include "graph_events.h"
#include "sends_all.h"
#include "player.h"

/* pex: Un joueur expulse */

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

/* pbc: Un joueur fait un broadcast */

bool	graph_pbc(void *data)
{
  char	*to_send;

  if (asprintf(&to_send, "pbc %d %s",
	       ((t_bdata *)data)->id,
	       ((t_bdata *)data)->msg) == -1)
    return (false);
  sends_all(to_send);
  free(((t_bdata *)data)->msg);
  free(data);
  free(to_send);
  return (true);
}

/* pfk: Le joueur pond un oeuf */

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

/* pdr: Le joueur jette une ressource */

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

/* pgt: Le joueur prend une ressource */

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
