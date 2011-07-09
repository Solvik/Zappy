/*
** sends_all.c for zappy in /home/gelin_g/Zappy/server_zappy/modules/graph_protocol
** 
** Made by guillaume gelin
** Login   <gelin_g@epitech.net>
** 
** Started on  Wed Jul  6 00:59:13 2011 guillaume gelin
** Last update Sat Jul  9 01:19:51 2011 ramnes
*/

#define		_GNU_SOURCE

#include	<stdio.h>
#include	<stdarg.h>
#include	"tserver.h"
#include	"napi.h"
#include	"sends_all.h"

static void    	_sends(void *player, void *msg)
{
  sends((t_fds *)player, (char *)msg);
}

void		sends_all(char *msg)
{
  t_module      *mod;

  mod = get_module_by_name("Graphic Protocol");
  foreach_arg_list(mod->clients, _sends, (void*)msg);
}

void		sendf_all(char const *format, ...)
{
  char		*string;
  va_list	arguments;

  va_start(arguments, format);
  if (vasprintf(&string, format, arguments) == -1)
    return;
  va_end(arguments);
  sends_all(string);
}

