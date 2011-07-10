/*
** gserv_get_map.c for Zappy in ./server_zappy/src
** 
** Made by di-mar_j
** Login   <di-mar_j@epitech.net>
** 
** Started on  Thu Jun 23 22:12:26 2011 di-mar_j
** Last update Sun Jul 10 23:15:49 2011 di-mar_j
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
