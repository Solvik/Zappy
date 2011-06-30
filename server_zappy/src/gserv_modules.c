/*
** gserv_modules.c for  in /Users/Lifely/Developer/project/Zappy/server_zappy
** 
** Made by Julien Di Marco
** Login   <Lifely@epitech.net>
** 
** Started on  Thu Jun 30 05:05:13 2011 Julien Di Marco
** Last update Thu Jun 30 05:05:13 2011 Julien Di Marco
*/

#include	<unistd.h>
#include	<stdlib.h>
#include	"tserver.h"

extern t_server *gserv;

bool		gserv_const(bool created)
{
  static bool	_const = false;

  if (created && !_const)
    gserv->module = get_modules();
  _const = (created ? true : _const);
  return (_const);
}

t_list		**singleton_module(void)
{
  static t_list	*module_manager = NULL;

  return ((gserv_const(false) ? &gserv->module : &module_manager));
}

t_list		*get_modules(void)
{
  return (*(singleton_module()));
}

bool		set_new_module(t_module *module)
{
  return (put_in_list(singleton_module(), module));
}
