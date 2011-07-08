/*
** gserv_available_names.c for  in /home/di-mar_j/git/Zappy/server_zappy
** 
** Made by julien di-marco
** Login   <di-mar_j@epitech.net>
** 
** Started on  Fri Jul  8 17:02:10 2011 julien di-marco
** Last update Fri Jul  8 17:02:10 2011 julien di-marco
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

