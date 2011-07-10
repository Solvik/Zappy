/*
** fork.c for  in /home/solvik/tek2/proj/Zappy/server_zappy/src
**
** Made by solvik blum
** Login   <blum_s@epitech.net>
**
** Started on  Mon Jun 13 12:46:13 2011 solvik blum
** Last update Sun Jul 10 14:12:32 2011 guillaume gelin
*/

#include        <stdlib.h>

#include        "napi.h"
#include        "zappy_protocol.h"

/*
** Del egg todo.
*/

bool            egg_eclosion(void *data)
{
  t_player      *player;
  t_egg         *egg;

  if (!(egg = (t_egg*)data))
    return (false);
  egg->team->max_conn++;
  if (!(player = new_player(egg->team->name)))
    return (false);
  player->fork = true;
  return (true);
}

int             zappy_fork(t_fds *client, char *_)
{
  t_player      *p;

  (void)_;
  if (!client || !(p = *(t_player**)client) ||
      !(p->egg = set_box_addegg(p)))
    {
      sends(client, "ko");
      return (false);
    }
  sends(client, "ok");
  event_relative_dispatch("EggNew", p->egg, 0);
  event_relative_dispatch("EggHatch", p->egg, 600);
  return (true);
}
