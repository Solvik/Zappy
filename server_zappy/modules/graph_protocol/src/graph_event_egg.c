/*
** graph_event_egg.c for zappy project
** 
** Made by ramnes
** <perso@ramnes.eu>
** 
** Started on  Fri Jul  8 02:37:42 2011 by ramnes
** Last update Fri Jul  8 09:53:33 2011 ramnes
*/

#include "graph_events.h"
#include "egg.h"
#include "sends_all.h"

/* EggNew */

bool	graph_enw(void *data)
{
  t_egg	*egg;

  egg = (t_egg *)data;
  sendf_all("enw %d %d %d %d", egg->id, egg->father->id, egg->x, egg->y);
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
  sendf_all("ebo %d", ((t_egg *)data)->id);
  return (true);
}

/* EggDied */

bool	graph_edi(void *data)
{
  sendf_all("edi %d", ((t_egg *)data)->id);
  return (true);
}
