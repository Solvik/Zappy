/*
** gserv_available_names.c for Zappy in ./server_zappy/src
** 
** Made by di-mar_j
** Login   <di-mar_j@epitech.net>
** 
** Started on  Thu Jun 23 22:12:26 2011 di-mar_j
** Last update Sun Jul 10 23:15:49 2011 di-mar_j
*/

#include	<unistd.h>
#include	<stdlib.h>
#include	<string.h>

#include	"tserver.h"

extern t_server *	gserv;

static bool	match_team(void *elem, void *a)
{
  t_team	*team;
  char		*name;

  if (!(team = (t_team*)elem) || !(name = (char*)a))
    return (false);
  return ((strcmp(team->name, name) == 0));
}

static bool	match_module(void *elem, void *a)
{
  t_module	*team;
  char		*name;

  if (!(team = (t_module*)elem) || !(name = (char*)a))
    return (false);
  return ((strcmp(team->name, name) == 0));
}

bool		available_modules(char * name)
{
  return (get_data_as_arg(gserv->module, match_module, name) ? true : false);
}

bool		available_teams(char * name)
{
  return (get_data_as_arg(gserv->team, match_team, name) ? true : false);
}

