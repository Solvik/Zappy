/*
** gserv_set_box_delfood.c for Zappy in ./server_zappy/src
** 
** Made by di-mar_j
** Login   <di-mar_j@epitech.net>
** 
** Started on  Thu Jun 23 22:12:26 2011 di-mar_j
** Last update Sun Jul 10 23:15:49 2011 di-mar_j
*/

#include		<stdlib.h>
#include		"stone.h"
#include		"tserver.h"
#include		"server_zappy.h"

extern t_server 	*gserv;

uint			set_box_delfood(uint x, uint y, uint nb)
{
  t_box 		*box;
  uint			tmp;

  if (!(box = get_box(x, y)))
    return (0);
  if ((tmp = box->food) < nb)
    {
      box->food = 0;
      return (tmp);
    }
  box->food -= nb;
  return (nb);
}
