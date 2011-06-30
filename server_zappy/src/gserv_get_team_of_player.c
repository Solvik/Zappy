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

static bool	match_player(void *data, void *arg)
{
  return (data == arg);
}

static bool	match_team(void *data, void *arg)
{
  return (get_data_as_arg(((t_team *)data)->players,
			  match_player, arg));
}

t_team		*get_team_of_player(t_player *player)
{
  return (get_data_as_arg(gserv->team, match_team, player));
}
