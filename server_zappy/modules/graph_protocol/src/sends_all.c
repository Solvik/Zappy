/*
** sends_all.c for Zappy in ./server_zappy/modules/graph_protocol/src
** 
** Made by di-mar_j
** Login   <di-mar_j@epitech.net>
** 
** Started on  Thu Jun 23 22:12:26 2011 di-mar_j
** Last update Sun Jul 10 23:15:49 2011 di-mar_j
*/

#define		_GNU_SOURCE

#include	<stdlib.h>
#include	<stdio.h>
#include	<stdlib.h>
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
  free(string);
}

