/*
** gserv_get_map.c for  in /Users/Lifely/Developer/project/Zappy/server_zappy
** 
** Made by Julien Di Marco
** Login   <Lifely@epitech.net>
** 
** Started on  Thu Jun 30 05:05:34 2011 Julien Di Marco
** Last update Mon Jul  4 15:57:20 2011 Sebastien Blot
*/

#include	<stdlib.h>
#include	"tserver.h"
#include	"server_zappy.h"

extern t_server *gserv;

uint		get_map_width(void)
{
  return (gserv->map.width);
}

uint		get_map_height(void)
{
  return (gserv->map.height);
}

t_box 		*get_map(void)
{
  return (gserv->map.map);
}

uint		get_map_max(void)
{
  return (get_map_height() * get_map_width());
}

t_box		*get_box(uint x, uint y)
{
  if (x >= get_map_width() || y >= get_map_height())
	return (NULL);
  return (&(gserv->map.map[x + (get_map_width() * y)]));
}
