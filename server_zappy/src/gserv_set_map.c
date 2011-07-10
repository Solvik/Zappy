/*
** gserv_set_map.c for Zappy in ./server_zappy/src
** 
** Made by di-mar_j
** Login   <di-mar_j@epitech.net>
** 
** Started on  Thu Jun 23 22:12:26 2011 di-mar_j
** Last update Sun Jul 10 23:15:49 2011 di-mar_j
*/

#include	"tserver.h"
#include	"server_zappy.h"

extern t_server *gserv;

void		set_map_width(uint width)
{
  gserv->map.width = width;
}

void		set_map_height(uint height)
{
  gserv->map.height = height;
}

void		set_map(t_box *map)
{
  gserv->map.map = map;
}
