/*
** gserv_get_box_nbfood.c for  in /home/solvik/tek2/proj/Zappy
**
** Made by solvik blum
** Login   <blum_s@epitech.net>
**
** Started on  Sat Jul  9 18:37:55 2011 solvik blum
** Last update Sat Jul  9 18:37:56 2011 solvik blum
*/

#include		<stdlib.h>
#include		"tserver.h"

uint			get_box_nbfood(uint x, uint y)
{
  t_box 	*box;

  if (!(box = get_box(x, y)))
    return (0);
  return (box->food);
}
