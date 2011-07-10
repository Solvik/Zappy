/*
** graph_event_egg.c for Zappy in ./server_zappy/modules/graph_protocol/src
** 
** Made by di-mar_j
** Login   <di-mar_j@epitech.net>
** 
** Started on  Thu Jun 23 22:12:26 2011 di-mar_j
** Last update Sun Jul 10 23:15:49 2011 di-mar_j
*/

#include "graph_events.h"
#include "egg.h"
#include "sends_all.h"

/* EggNew */
bool	graph_enw(void *data)
{
  t_egg	*egg;

  egg = (t_egg *)data;
  sendf_all("enw %d %d %d %d", egg->id, egg->idf, egg->x, egg->y);
  return (true);
}

/* EggHatch */
bool	graph_eht(void *data)
{
  sendf_all("eht %d", ((t_egg *)data)->id);
  return (true);
}

/* EggBound */
bool	graph_ebo(void *data)
{
  sendf_all("ebo %d", ((t_player *)data)->id);
  return (true);
}

/* EggDied */
bool	graph_edi(void *data)
{
  sendf_all("edi %d", ((t_egg *)data)->id);
  return (true);
}
