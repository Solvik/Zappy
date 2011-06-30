/*
** gserv_get_teams.c for  in /Users/Lifely/Developer/project/Zappy/server_zappy
** 
** Made by Julien Di Marco
** Login   <Lifely@epitech.net>
** 
** Started on  Thu Jun 30 05:05:18 2011 Julien Di Marco
** Last update Thu Jun 30 05:05:18 2011 Julien Di Marco
*/

#include	"tserver.h"

extern t_server *	gserv;

t_list *	get_teams(void)
{
  return (gserv->team);
}

t_box *		get_box_at(uint i)
{
  if (i < get_map_max())
    return (NULL);
  return (&(gserv->map.map[i]));
}
