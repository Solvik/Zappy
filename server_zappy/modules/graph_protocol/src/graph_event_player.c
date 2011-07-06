/*
** graph_event_player.c for zappy project
** 
** Made by ramnes
** <perso@ramnes.eu>
** 
** Started on  Wed Jul  6 16:43:06 2011 by ramnes
** Last update Wed Jul  6 17:03:43 2011 ramnes
*/

#define	_GNU_SOURCE

#include <stdio.h>
#include <stdlib.h>
#include "tserver.h"
#include "graph_events.h"
#include "sends_all.h"
#include "player.h"

/* pfk: Le joueur pond un oeuf */

bool	graph_pfk(void *data)
{
  t_fds *client;
  char	*to_send;

  client = (t_fds *)data;
  asprintf(&to_send, "pfk %d", player_data->id);
  sends_all(to_send);
  free(to_send);
  return (true);
}

/* pdr: Le joueur jette une ressource */

bool	graph_pdr(void *data)
{
  char	*to_send;

  asprintf(&to_send, "pdr %d %d", 0 /* id */, 42 /* numero de ressource */);
  sends_all(to_send);
  free(to_send);
  return (true);
}

/* pgt: Le joueur prend une ressource */

bool	graph_pgt(void *data)
{
  char	*to_send;

  asprintf(&to_send, "pgt %d %d", 0 /* id */, 42 /* numero de ressource */);
  sends_all(to_send);
  free(to_send);
  return (true);
}

/* pdi: Le joueur est mort de faim */

bool	graph_pdi(void *data)
{
  t_fds *client;
  char	*to_send;

  client = (t_fds *)data;
  asprintf(&to_send, "pdi %d", player_data->id);
  sends_all(to_send);
  free(to_send);
  return (true);
}
