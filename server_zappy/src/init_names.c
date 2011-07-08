/*
** init_names.c for  in /home/di-mar_j/git/Zappy/server_zappy
** 
** Made by julien di-marco
** Login   <di-mar_j@epitech.net>
** 
** Started on  Fri Jul  8 16:48:11 2011 julien di-marco
** Last update Fri Jul  8 16:48:11 2011 julien di-marco
*/

#include	<unistd.h>
#include	<stdlib.h>
#include	<string.h>
#include	<stdio.h>

#include	"zopt.h"
#include	"tserver.h"

#include	"team.h"

extern t_server *	gserv;

void 		add_team(void *elem)
{
  char		*name;
  t_team	*team;

  if (!gserv_const(false) || !gserv ||
      !(name = (char*)elem) || !(team = calloc(1, sizeof(*team))))
    return ;
  team->name = strdup(name);
  team->max_conn = get_nb_clients();
  put_in_list(&gserv->team, team);
}

bool		init_team(t_zopt * opt)
{
  if (!gserv_const(false) || !gserv || !opt)
    return (false);
  foreach_list(opt->team, add_team);
  return (true);
}
