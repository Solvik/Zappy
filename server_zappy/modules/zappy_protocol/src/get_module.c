/*
** get_module.c for  in /Users/Lifely/Developer/project/Zappy/server_zappy/modules/zappy_protocol
**
** Made by Julien Di Marco
** Login   <Lifely@epitech.net>
**
** Started on  Thu Jun 30 03:50:51 2011 Julien Di Marco
** Last update Thu Jun 30 03:50:51 2011 Julien Di Marco
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
** prend
** pose
** broadcast
** incantation
** fork
** connect_nbr
**
*/

static void		init_commands(t_mod_func *func)
{
  add_command(func, "broadcast", zappy_broadcast);
  add_command(func, "avance", zappy_avance);
  add_command(func, "droite", zappy_droite);
  add_command(func, "gauche", zappy_gauche);
  add_command(func, "voir", zappy_voir);
  add_command(func, "inventaire", zappy_inventaire);
  add_command(func, "expulse", zappy_expulse);
  add_command(func, "prend", zappy_prend);
  add_command(func, "pose", zappy_pose);
  add_command(func, "incantation", zappy_incantation);
  add_command(func, "fork", zappy_fork);
  add_command(func, "connect_nbr", zappy_connect_nbr);
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
