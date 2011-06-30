/*
** gserv_set_map.c for  in /Users/Lifely/Developer/project/Zappy/server_zappy
** 
** Made by Julien Di Marco
** Login   <Lifely@epitech.net>
** 
** Started on  Thu Jun 30 05:05:10 2011 Julien Di Marco
** Last update Thu Jun 30 05:05:10 2011 Julien Di Marco
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
