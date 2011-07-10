/*
** init_names.c for Zappy in ./server_zappy/src
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
