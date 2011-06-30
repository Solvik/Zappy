/*
** voir.c for  in /home/solvik/tek2/proj/Zappy/server_zappy/src
**
** Made by solvik blum
** Login   <blum_s@epitech.net>
**
** Started on  Mon Jun 13 12:46:13 2011 solvik blum
** Last update Wed Jun 29 17:12:51 2011 solvik blum
*/

#include <stdlib.h>

#include "player.h"
#include "server_zappy.h"

int		zappy_pose(t_fds *client, char *_)
{
  (void)_;
  sends(client, "ok");
  return (1);
}
