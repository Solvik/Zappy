/*
** refresh.c for Zappy in ./client_zappy/src
** 
** Made by di-mar_j
** Login   <di-mar_j@epitech.net>
** 
** Started on  Thu Jun 23 22:12:26 2011 di-mar_j
** Last update Sun Jul 10 23:15:49 2011 di-mar_j
*/

#include	"client_zappy.h"

void		refresh_screen(t_visu *v)
{
  int		x;
  int		y;

  draw_map(v);
  foreach_arg_list(v->player, draw_player, v);
  x = 0;
  while (x < v->width)
    {
      y = 0;
      while (y < v->height)
	{
	  draw_stones(v, x, y);
	  y++;
	}
      x++;
    }
}
