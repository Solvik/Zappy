/*
** droite.c for  in /home/solvik/tek2/proj/Zappy/server_zappy/src/protocol
**
** Made by solvik blum
** Login   <blum_s@epitech.net>
**
** Started on  Mon Jun 13 16:50:23 2011 solvik blum
** Last update Mon Jun 13 19:33:02 2011 solvik blum
*/

#include <stdlib.h>

#include "player.h"
#include "server_zappy.h"


int		zappy_droite(fds *client)
{
  client_data->direction = (client_data->direction + 1) % 4;
  send(client, "OK\n");
  return (0);
}
