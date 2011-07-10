/*
** gserv_set_box_delegg.c for Zappy in ./server_zappy/src
** 
** Made by di-mar_j
** Login   <di-mar_j@epitech.net>
** 
** Started on  Thu Jun 23 22:12:26 2011 di-mar_j
** Last update Sun Jul 10 23:15:49 2011 di-mar_j
*/

#include	<stdlib.h>
#include	"egg.h"
#include	"map.h"
#include	"tserver.h"

bool		match_egg(void * data, void * arg)
{
  return (data == arg);
}

void		set_box_delegg(t_egg * egg)
{
  t_box *	box;

  if (!(box = get_box(egg->x, egg->y)) ||
      !del_node_as_arg(&box->eggs, match_egg, egg))
    return ;
  free(egg);
}
