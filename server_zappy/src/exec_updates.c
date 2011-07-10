/*
** exec_updates.c for Zappy in ./server_zappy/src
** 
** Made by di-mar_j
** Login   <di-mar_j@epitech.net>
** 
** Started on  Thu Jun 23 22:12:26 2011 di-mar_j
** Last update Sun Jul 10 23:15:49 2011 di-mar_j
*/

#include	<unistd.h>
#include	<stdlib.h>
#include	<stdio.h>

#include	"tserver.h"
#include	"module.h"

static void		module_updates(t_module *elem, double *arg)
{
  if (!elem || !arg)
    return ;
  if (!elem->update)
    return ;
  elem->update(*arg);
}

bool		exec_updates(double tdt)
{
  t_list	*modules;

  if (!(modules = get_modules()))
    return (false);
  foreach_arg_list(modules, (void(*)(void*, void*))module_updates, &tdt);
  return (true);
}
