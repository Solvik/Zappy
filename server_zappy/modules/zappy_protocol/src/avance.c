/*
** avance.c for  in /home/solvik/tek2/proj/Zappy/server_zappy/src/protocol
**
** Made by solvik blum
** Login   <blum_s@epitech.net>
**
** Started on  Mon Jun 13 15:55:53 2011 solvik blum
** Last update Thu Jul  7 20:53:57 2011 ramnes
*/

#include	<stdlib.h>
#include	"napi.h"
#include	"map.h"
#include	"player.h"
#include	"server_zappy.h"
#include	"tserver.h"

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
  p->x += (p->direction == WEST) ? 1 : (p->direction == EAST) ? -1 : 0;
  p->y += (p->direction == NORTH) ? 1 : (p->direction == SOUTH) ? -1 : 0;
  p->x = X(p->x);
  p->y = Y(p->y);
  sends(c, "ok");
  event_relative_dispatch("PlayerMove", c, 0);
  return (true);
}
