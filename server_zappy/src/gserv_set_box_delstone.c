/*
** gserv_set_box_delstone.c for  in /Users/Lifely/Developer/project/Zappy/server_zappy
** 
** Made by Julien Di Marco
** Login   <Lifely@epitech.net>
** 
** Started on  Thu Jun 30 05:05:03 2011 Julien Di Marco
** Last update Thu Jun 30 05:05:03 2011 Julien Di Marco
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
