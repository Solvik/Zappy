/*
** voir.c for  in /home/solvik/tek2/proj/Zappy/server_zappy/src
**
** Made by solvik blum
** Login   <blum_s@epitech.net>
**
** Started on  Mon Jun 13 12:46:13 2011 solvik blum
** Last update Wed Jun 29 17:12:59 2011 solvik blum
*/

#include <stdlib.h>

#include "player.h"
#include "server_zappy.h"


int		zappy_broadcast(t_fds *client, char *cmd)
{
  (void)cmd;
  sends(client, "ok");
  return (1);
}
