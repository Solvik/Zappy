/*
** gserv_get_team_of_player.c for Zappy in ./server_zappy/src
** 
** Made by di-mar_j
** Login   <di-mar_j@epitech.net>
** 
** Started on  Thu Jun 23 22:12:26 2011 di-mar_j
** Last update Sun Jul 10 23:15:49 2011 di-mar_j
*/

#include	<string.h>
#include	"tserver.h"

extern t_server *gserv;

t_team		*get_team_of_player(t_player *player)
{
  return (player ? player->team : NULL);
}
