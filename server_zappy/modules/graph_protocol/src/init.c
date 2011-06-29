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
#include	"graph_map.h"
#include	"module.h"


/*
 * TODO : Mettre le bon nombre de fonction dans le malloc
 */

t_module *	get_module(void)
{
  t_module *	module;

  if (!(module = malloc(sizeof(*module) + sizeof(t_mod_func) * 40)))
    return (NULL);
  bzero(module, sizeof(*module));
  module->name = strdup("Graphic Protocol");
  module->delim = strdup("\n");
  module->port = 4242;
  module->antiflood = 10;
  module->clients = NULL;
  module->functions[0].command = strdup("msz");
  module->functions[0].action = graph_msz;
  module->functions[1].command = strdup("graphic");
  module->functions[1].action = graph_msz;
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
