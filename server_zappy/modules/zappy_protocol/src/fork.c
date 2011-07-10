/*
** voir.c for  in /home/solvik/tek2/proj/Zappy/server_zappy/src
**
** Made by solvik blum
** Login   <blum_s@epitech.net>
**
** Started on  Mon Jun 13 12:46:13 2011 solvik blum
<<<<<<< Updated upstream
** Last update Sun Jul 10 04:43:09 2011 guillaume gelin
=======
** Last update Sun Jul 10 04:38:10 2011 guillaume gelin
>>>>>>> Stashed changes
*/

#include	<stdlib.h>

#include	"napi.h"

bool		egg_eclosion(void *data)
{
  t_player	*player;

  ((t_egg *)data)->team->max_conn++;
  if ((player = new_player(((t_egg *)data)->team->name)) == NULL)
    return (false);
  return (true);
}

int		zappy_fork(t_fds *client, char *_)
{
  t_player	*p;
  t_egg		*egg;

  (void)_;
  if (!client || !(p = *(t_player**)client) || !(egg = set_box_addegg(p)))
    return (false);
  event_relative_dispatch("Fork", client, 0);
  /* ramnes: need sheduler 42/t */
  event_relative_dispatch("EggNew", egg, 0);
  event_relative_dispatch("EggHatch", egg, 600);
  sends(client, "ok");
  return (1);
}
