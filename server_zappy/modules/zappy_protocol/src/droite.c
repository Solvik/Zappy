/*
** droite.c for  in /home/solvik/tek2/proj/Zappy/server_zappy/src/protocol
**
** Made by solvik blum
** Login   <blum_s@epitech.net>
**
** Started on  Mon Jun 13 16:50:23 2011 solvik blum
** Last update Thu Jul  7 20:54:42 2011 ramnes
*/

#include "napi.h"

int		zappy_droite(t_fds *c, char *_)
{
  t_player	*p;

  (void)_;
  if (!c || !(p = *(t_player**)c))
    return (false);
  p->direction = (p->direction + 1) % (WEST + 1);
  sends(c, "ok");
  event_relative_dispatch("PlayerMove", c, 0);
  return (true);
}
