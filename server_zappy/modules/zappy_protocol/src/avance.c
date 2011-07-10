/*
** avance.c for Zappy in ./server_zappy/modules/zappy_protocol/src
** 
** Made by di-mar_j
** Login   <di-mar_j@epitech.net>
** 
** Started on  Thu Jun 23 22:12:26 2011 di-mar_j
** Last update Sun Jul 10 23:15:49 2011 di-mar_j
*/

#include	<stdlib.h>
#include	<stdio.h>

#include	"napi.h"

int		zappy_avance(t_fds *c, char *_)
{
  t_player	*p;

  (void)_;
  if (!c || !(p = *(t_player**)c))
    {
      sends(c, "ko");
      return (false);
    }
  print_debug_(true, "[%d] - {x: %d, y: %d} -->", p->direction, p->x, p->y);
  set_box_delplayer(p);
  p->x += (p->direction == WEST) ? 1 : (p->direction == EAST) ? -1 : 0;
  p->y += (p->direction == NORTH) ? 1 : (p->direction == SOUTH) ? -1 : 0;
  print_debug_(false, "[%d] - {x: %d, y: %d} -->", p->direction, p->x, p->y);
  p->x = X(p->x);
  p->y = Y(p->y);
  set_box_addplayer(p, p->x, p->y);
  print_debug_(false, " {x: %d, y: %d}\n", p->x, p->y);
  sends(c, "ok");
  event_relative_dispatch("PlayerMove", c, 0);
  return (true);
}
