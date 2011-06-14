/*
** voir.c for  in /home/solvik/tek2/proj/Zappy/server_zappy/src
**
** Made by solvik blum
** Login   <blum_s@epitech.net>
**
** Started on  Mon Jun 13 12:46:13 2011 solvik blum
** Last update Tue Jun 14 17:27:32 2011 solvik blum
*/

#include <stdlib.h>

#include "player.h"
#include "server_zappy.h"

static char     *gl_ressource_name[] =
  {
    " nourriture",
    " linemate",
    " deraumere",
    " sibur",
    " mendiane",
    " phiras",
    " thystame"
  };

int		zappy_voir(t_fds *player)
{
  /* on recup le lvl */
  int		level;

  level = player_data->level;

  /* en fonction du level, on itere sur X */
  /* ... */
}

