/*
** init.c for  in /home/seb/git/Zappy/server_zappy/src/graph_protocol
**
** Made by seb
** Login   <seb@epitech.net>
**
** Started on  Mon Jun 20 12:10:00 2011 seb
** Last update Wed Jul  6 00:42:31 2011 guillaume gelin
*/

#include	<stdio.h>
#include	<string.h>
#include	<strings.h>
#include	<stdlib.h>

#include	"napi.h"

#include	"graph_map.h"
#include	"graph_graphic.h"
#include	"graph_team.h"
#include	"graph_time.h"
#include	"graph_player.h"
#include	"graph_event_global.h"

t_module *	get_module(void)
{
  t_module *	module;

  if (!(module = malloc(sizeof(*module) + sizeof(t_mod_func) * 40)))
    return (NULL);
  bzero(module, sizeof(*module) + sizeof(t_mod_func) * 40);
  module->name = strdup("Graphic Protocol");
  module->delim = strdup("\n");
  module->port = 4242;
  module->antiflood = 10;
  module->clients = NULL;
  command_add(module->functions, "graphic", graph_graphic);
  command_add(module->functions, "msz", graph_msz);
  command_add(module->functions, "bct", graph_bct);
  command_add(module->functions, "mct", graph_mct);
  command_add(module->functions, "tna", graph_tna);
  command_add(module->functions, "ppo", graph_ppo);
  command_add(module->functions, "plv", graph_plv);
  command_add(module->functions, "pin", graph_pin);
  command_add(module->functions, "sgt", graph_sgt);
  command_add(module->functions, "sst", graph_sst);
  event_catch("pnw", graph_pnw);
  event_catch("pex", graph_pex);
  event_catch("pbc", graph_pbc);
  return (module);
}

#if	defined(NOTSHARED)
__attribute__ ((constructor))
void	init_(void)
{
  mod_register(get_module());
}
#endif

bool		handshaking(t_fds *client, char *cmd)
{
  if (!client->anounce)
    sends(client, "BIENVENUE");
  if (cmd && (strcmp(cmd, "GRAPHIC") == 0))
    {
      graph_graphic(client, cmd);
      return (true);
    }
  return (false);
}
