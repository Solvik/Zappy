/*
** exec_updates.c for  in /Users/Lifely/Developer/project/Zappy/server_zappy
** 
** Made by Julien Di Marco
** Login   <Lifely@epitech.net>
** 
** Started on  Sat Jul  2 03:36:17 2011 Julien Di Marco
** Last update Sat Jul  2 03:36:17 2011 Julien Di Marco
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
