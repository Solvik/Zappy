/*
** graph_player.h for  in /home/seb/git/Zappy/server_zappy/src/graph_protocol
**
** Made by seb
** Login   <seb@epitech.net>
**
** Started on  Tue Jun 14 16:22:31 2011 seb
** Last update Tue Jun 14 16:22:31 2011 seb
*/

#ifndef GRAPH_PLAYER_H_
#define GRAPH_PLAYER_H_

#include <stdbool.h>
#include "network.h"

bool handle_ppo(t_fds *, char *);
bool handle_plv(t_fds *, char *);
bool handle_pin(t_fds *, char *);
bool handle_pnw(t_fds *, char *);

#endif
