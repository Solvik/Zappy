/*
** init_map.c for  in /Users/Lifely/Developer/project/Zappy/server_zappy
** 
** Made by Julien Di Marco
** Login   <Lifely@epitech.net>
** 
** Started on  Thu Jun 30 05:04:58 2011 Julien Di Marco
** Last update Thu Jun 30 05:04:58 2011 Julien Di Marco
*/

#include	<strings.h>
#include	<stdlib.h>
#include	"map.h"
#include	"zopt.h"
#include	"error.h"
#include	"tserver.h"
#include	"server_zappy.h"

bool		init_map(t_zopt *opt)
{
  t_box *	map_ptr;

  set_map_width(opt->width);
  set_map_height(opt->height);
  if (!(map_ptr = malloc(((get_map_width() * get_map_height()) + 1)
			 * sizeof(*map_ptr))))
    return (print_perror("malloc"));
  bzero(map_ptr, (((get_map_width() * get_map_height()) + 1)
		  * sizeof(*map_ptr)));
  set_map(map_ptr);
  return (true);
}
