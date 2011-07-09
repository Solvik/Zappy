/*
** voir.c for  in /home/solvik/tek2/proj/Zappy/server_zappy/src
**
** Made by solvik blum
** Login   <blum_s@epitech.net>
**
** Started on  Mon Jun 13 12:46:13 2011 solvik blum
** Last update Sat Jul  9 18:52:08 2011 ramnes
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

int		zappy_fork(t_fds *client, char *cmd)
{
  t_egg		*egg;

  (void)cmd;
  if (!(egg = set_box_addegg(player_data)))
    return (0);
  event_relative_dispatch("EggNew", egg, 0);
  event_relative_dispatch("EggHatch", egg, 600);
  sends(client, "ok");
  return (1);
}
