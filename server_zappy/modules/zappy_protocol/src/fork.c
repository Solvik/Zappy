/*
** voir.c for  in /home/solvik/tek2/proj/Zappy/server_zappy/src
**
** Made by solvik blum
** Login   <blum_s@epitech.net>
**
** Started on  Mon Jun 13 12:46:13 2011 solvik blum
** Last update Tue Jul  5 18:02:09 2011 solvik blum
*/

#include	<stdlib.h>
#include	<stdio.h>

#include	"napi.h"

bool		egg_eclosion(void *data)
{
  t_player	*player;

  printf("coucou %d %d\n", ((t_egg *)data)->x, ((t_egg *)data)->y);
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
  event_relative_dispatch("egg_eclosion", egg, 600);
  sends(client, "ok");
  return (1);
}
