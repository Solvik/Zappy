/*
** gserv_set_box_addfood.c for Zappy in ./server_zappy/src
** 
** Made by di-mar_j
** Login   <di-mar_j@epitech.net>
** 
** Started on  Thu Jun 23 22:12:26 2011 di-mar_j
** Last update Sun Jul 10 23:15:49 2011 di-mar_j
*/

#include		<stdlib.h>
#include		"tserver.h"
#include		"server_zappy.h"

bool			set_box_addfood(uint x, uint y, uint nb)
{
  t_box 		*box;

  if (!(box = get_box(x, y)))
    return (false);
  box->food += nb;
  return (true);
}
