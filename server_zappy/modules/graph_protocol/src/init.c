/*
** init.c for  in /home/seb/git/Zappy/server_zappy/src/graph_protocol
**
** Made by seb
** Login   <seb@epitech.net>
**
** Started on  Mon Jun 20 12:10:00 2011 seb
** Last update Mon Jun 20 12:10:00 2011 seb
*/

#include	<stdio.h>
#include	<string.h>
#include	<strings.h>
#include	<stdlib.h>
#include	"module.h"

t_module *	get_module(void)
{
  t_module *	module;

  if (!(module = malloc(sizeof(*module))))
    return (NULL);
  bzero(module, sizeof(*module));
  module->name = strdup("Graphic Protocol");
  module->delim = strdup("\n");
  module->port = 1337;
  module->antiflood = 10;
  module->clients = NULL;
  return (module);
}

#if	defined(NOTSHARED)
__attribute__ ((constructor))
void	init_(void)
{
  mod_register(get_module());
}
#endif
