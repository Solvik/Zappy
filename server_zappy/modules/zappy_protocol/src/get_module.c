
/*
** get_module.c for  in /Users/Lifely/Developer/project/Zappy/server_zappy/modules/zappy_protocol
**
** Made by Julien Di Marco
** Login   <Lifely@epitech.net>
**
** Started on  Thu Jun 30 03:50:51 2011 Julien Di Marco
** Last update Mon Jul  4 19:45:09 2011 Sebastien Blot
*/

#include	<strings.h>
#include	<unistd.h>
#include	<stdlib.h>
#include	<string.h>
#include	<stdio.h>

#include	"napi.h"
#include	"tserver.h"

#include	"zappy_protocol.h"

/*
**
** avance : OK
** droite : OK
** gauche : OK
** voir : OK
** inventaire : OK
** expulse : OK
** prend : OK
** pose
** broadcast
** incantation
** fork
** connect_nbr
**
*/

static void		init_commands(t_mod_func *func)
{
  command_relative(func, "avance",	zappy_avance, 7);
  command_relative(func, "droite",	zappy_droite, 7);
  command_relative(func, "gauche",	zappy_gauche, 7);
  command_relative(func, "voir",	zappy_voir, 7);
  command_relative(func, "inventaire",	zappy_inventaire, 1);
  command_relative(func, "prend",	zappy_prend, 7);
  command_relative(func, "pose",	zappy_pose, 7);
  command_relative(func, "expulse",	zappy_expulse, 7);
  command_relative(func, "broadcast",	zappy_broadcast, 7);
  command_relative(func, "incantation",	zappy_incantation, 300);
  command_relative(func, "fork",	zappy_fork, 42);
  command_add(func, "connect_nbr",	zappy_connect_nbr);
}

t_module	*get_module(void)
{
  t_module	*module;

  if (!(module = malloc(sizeof(*module) + sizeof(t_mod_func) * 12)))
    return (NULL);
  bzero(module, sizeof(*module) + sizeof(t_mod_func) * 12);
  module->name = strdup("Zappy Protocol");
  module->delim = strdup("\r\n");
  module->port = -1;
  module->antiflood = 10;
  module->clients = NULL;
  init_commands(module->functions);
  return (module);
}
