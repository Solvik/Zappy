/*
** gserv_set_box_delstone.c for Zappy in ./server_zappy/src
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

static bool		match_stone(void *data, void *stone)
{
  return (((t_stone *)data)->type == *((e_stone *)stone));
}

uint			set_box_delstone(uint x, uint y,
					e_stone type, uint nb)
{
  t_box 		*box;
  t_stone 		*stone;
  uint			tmp;

  if (!(box = get_box(x, y)) ||
      !(stone = get_data_as_arg(box->stones, match_stone, &type)))
    return (0);
  if ((tmp = stone->nb) < nb)
    {
      stone->nb = 0;
      return (tmp);
    }
  stone->nb -= nb;
  return (nb);
}
