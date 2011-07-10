/*
** gserv_get_team_by_name.c for Zappy in ./server_zappy/src
** 
** Made by di-mar_j
** Login   <di-mar_j@epitech.net>
** 
** Started on  Thu Jun 23 22:12:26 2011 di-mar_j
** Last update Sun Jul 10 23:15:49 2011 di-mar_j
*/

#include		<string.h>
#include		"tserver.h"

extern t_server 	*gserv;

bool			match_team(void *data, void *name)
{
  return (!(strcmp(((t_team *)data)->name, (char *)name)));
}

t_team *		get_team_by_name(char *name)
{
  return (get_data_as_arg(gserv->team, match_team, name));
}
