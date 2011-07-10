/*
** gauche.c for Zappy in ./server_zappy/modules/zappy_protocol/src
** 
** Made by di-mar_j
** Login   <di-mar_j@epitech.net>
** 
** Started on  Thu Jun 23 22:12:26 2011 di-mar_j
** Last update Sun Jul 10 23:15:49 2011 di-mar_j
*/

#include "napi.h"

int		zappy_gauche(t_fds *c, char *_)
{
  t_player	*p;

  (void)_;
  if (!c || !(p = *(t_player**)c))
    return (false);
  p->direction = (p->direction + 3) % 4;
  sends(c, "ok");
  event_relative_dispatch("PlayerMove", c, 0);
  return (true);
}
