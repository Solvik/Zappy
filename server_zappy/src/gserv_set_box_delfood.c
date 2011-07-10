/*
** gserv_set_box_delfood.c for  in /home/solvik/tek2/proj/Zappy/server_zappy/src
**
** Made by solvik blum
** Login   <blum_s@epitech.net>
**
** Started on  Sun Jul  3 16:04:23 2011 solvik blum
** Last update Sat Jul  9 18:39:36 2011 solvik blum
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
