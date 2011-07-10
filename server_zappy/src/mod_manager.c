/*
** mod_manager.c for Zappy in ./server_zappy/src
** 
** Made by di-mar_j
** Login   <di-mar_j@epitech.net>
** 
** Started on  Thu Jun 23 22:12:26 2011 di-mar_j
** Last update Sun Jul 10 23:15:49 2011 di-mar_j
*/

#include	<string.h>
#include	<unistd.h>
#include	<stdlib.h>
#include	<stdio.h>
#include	"util_string.h"

#include	"tserver.h"
#include	"net.h"
#include	"network.h"
#include	"module.h"
#include	"error.h"

extern t_server	*gserv;

static bool	mod_unique(void *elem, void *arg)
{
  char	*lower;

  if (!arg)
    return (false);
  if (elem && (lower = ((t_module*)elem)->name) &&		\
      (strcasecmp(arg, lower) == 0))
    return (true);
  return (false);
}

bool		mod_register(t_module * new)
{
  if (!new)
    return (false);
  if ((foreach_arg_stop_list(get_modules(), mod_unique, new->name)))
    return (syntax_print_error("Module with the same name already loaded."));
  if (gserv_const(false))
    net_bind(&new->port);
  if (!set_new_module(new))
    return (syntax_print_error("unable to set module.\n"));
  return (true);
}
