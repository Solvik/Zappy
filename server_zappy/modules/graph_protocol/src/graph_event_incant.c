/*
** graph_event_incant.c for zappy project
**
** Made by ramnes
** <perso@ramnes.eu>
**
** Started on  Fri Jul  8 02:34:53 2011 by ramnes
** Last update Fri Jul  8 10:36:02 2011 ramnes
*/

#include "graph_events.h"

/* pic: IncaNew */

bool	graph_pic(void *data)
{
  /*
  ** ramnes: TODO
  ** understand the shit
  ** and code the shit
  ** but b4 : dodo
  */
  return (true);
}

/* pie: IncaEnd */

bool	graph_pie(void *data)
{
  sendf_all("pie %d %d %d",
	    ((t_generic *)data)->ui1,
	    ((t_generic *)data)->ui2,
	    ((t_generic *)data)->ui3);
  return (true);
}

