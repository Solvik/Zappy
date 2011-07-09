/*
** gserv_get_team_of_player.c for  in /Users/Lifely/Developer/project/Zappy/server_zappy
** 
** Made by Julien Di Marco
** Login   <Lifely@epitech.net>
** 
** Started on  Thu Jun 30 05:05:22 2011 Julien Di Marco
** Last update Thu Jun 30 05:05:22 2011 Julien Di Marco
*/

#include	<string.h>
#include	"tserver.h"

extern t_server *gserv;

t_team		*get_team_of_player(t_player *player)
{
  return (player ? player->team : NULL);
}
