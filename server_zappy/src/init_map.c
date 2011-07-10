/*
** init_map.c for Zappy in ./server_zappy/src
** 
** Made by di-mar_j
** Login   <di-mar_j@epitech.net>
** 
** Started on  Thu Jun 23 22:12:26 2011 di-mar_j
** Last update Sun Jul 10 23:15:49 2011 di-mar_j
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
  t_box 	*map_ptr;

  set_map_width(opt->width);
  set_map_height(opt->height);
  if (!(map_ptr = malloc(((get_map_width() * get_map_height()) + 1)
			 * sizeof(*map_ptr))))
    return (print_perror("malloc"));
  bzero(map_ptr, (((get_map_width() * get_map_height()) + 1)
		  * sizeof(*map_ptr)));
  set_map(map_ptr);
  map_random_fill();
  return (true);
}
