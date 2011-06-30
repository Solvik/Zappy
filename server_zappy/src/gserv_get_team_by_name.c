/*
** gserv_get_team_by_name.c for  in /Users/Lifely/Developer/project/Zappy/server_zappy
** 
** Made by Julien Di Marco
** Login   <Lifely@epitech.net>
** 
** Started on  Thu Jun 30 05:05:25 2011 Julien Di Marco
** Last update Thu Jun 30 05:05:25 2011 Julien Di Marco
*/

#include		<string.h>
#include		"tserver.h"

extern t_server *	gserv;

bool			match_team(void * data, void * name)
{
  return (!(strcmp(((t_team *)data)->name, (char *)name)));
}

t_team *		get_team_by_name(char * name)
{
  return (get_data_as_arg(gserv->team, match_team, name));
}
