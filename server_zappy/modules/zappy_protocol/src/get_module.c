/*
** get_module.c for  in /Users/Lifely/Developer/project/Zappy/server_zappy/modules/zappy_protocol
**
** Made by Julien Di Marco
** Login   <Lifely@epitech.net>
**
** Started on  Thu Jun 30 03:50:51 2011 Julien Di Marco
** Last update Sat Jul  9 18:49:11 2011 ramnes
*/

#include	<strings.h>
#include	<unistd.h>
#include	<stdlib.h>
#include	<string.h>
#include	<stdio.h>

#include	"napi.h"

#include	"zappy_protocol.h"

static void		init_commands(t_mod_func *func)
{
  command_relative(func, "avance", zappy_avance, 7);
  command_relative(func, "droite", zappy_droite, 7);
  command_relative(func, "gauche", zappy_gauche, 7);
  command_relative(func, "voir", zappy_voir, 7);
  command_relative(func, "inventaire", zappy_inventaire, 1);
  command_relative(func, "prend", zappy_prend, 7);
  command_relative(func, "pose", zappy_pose, 7);
  command_relative(func, "expulse", zappy_expulse, 7);
  command_relative(func, "broadcast", zappy_broadcast, 7);
  command_relative(func, "incantation", zappy_incantation, 300);
  command_relative(func, "fork", zappy_fork, 42);
  command_add(func, "connect_nbr", zappy_connect_nbr);
  event_catch("EggHatch", egg_eclosion);
}

t_module	*get_module(void)
{
  if (!(zappy_module = malloc(SIZEMODULE(12))))
    return (NULL);
  bzero(zappy_module, SIZEMODULE(12));
  zappy_module->name = strdup("Zappy Protocol");
  zappy_module->delim = strdup("\r\n");
  zappy_module->port = -1;
  zappy_module->antiflood = 10;
  zappy_module->clients = NULL;
  init_commands(zappy_module->functions);
  return (zappy_module);
}
