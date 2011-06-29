
#include	<stdio.h>
#include	<string.h>
#include	<strings.h>
#include	<stdlib.h>

#include	"module.h"
#include	"network.h"
#include	"zappy_protocol.h"

void		init_func(t_mod_func *mod_func, char *cmd, void *func)
{
  static int	i = 0;

  mod_func[i].command = strdup(cmd);
  mod_func[i++].action = func;
}

void		init_commands(t_mod_func *func)
{
  init_func(func, "avance",		zappy_avance); /* OK */
  init_func(func, "droite",		zappy_droite); /* OK */
  init_func(func, "gauche",		zappy_gauche);  /* OK */
  init_func(func, "voir",		zappy_voir);
  init_func(func, "inventaire",		zappy_inventaire); /* OK */
  init_func(func, "prend objet",	zappy_prend_objet);
  init_func(func, "pose objet",		zappy_pose_objet);
  init_func(func, "expulse",		zappy_expulse); /* OK */
  init_func(func, "broadcast texte",	zappy_broadcast_texte);
  init_func(func, "incantation",	zappy_incantation);
  init_func(func, "fork",		zappy_fork);
  init_func(func, "connect_nbr",	zappy_connect_nbr);
}

t_module	*get_module(void)
{
  t_module	*module;

  if (!(module = malloc(sizeof(*module) + sizeof(t_mod_func) * 5)))
    return (NULL);
  bzero(module, sizeof(*module) + sizeof(t_mod_func) * 5);
  module->name = strdup("Zappy Protocol");
  module->delim = strdup("\r\n");
  module->port = -1;
  module->antiflood = 10;
  module->clients = NULL;
  init_commands(module->functions);
  return (module);
}

bool		test(fds client, char *cmd)
{
  (void)client;
  printf("WORKING : [%s]\n", cmd);
  return (true);
}

bool		handshaking(fds client, char *cmd)
{
  if (!client->anounce)
    sends(client, "BIENVENU");
  if (cmd && (strcmp(cmd, "hello") == 0))
    return (true);
  return (false);
}

#if	defined(NOTSHARED)
__attribute__ ((constructor))
void	init_(void)
{
  t_module	*info;

  printf("Should really work !\n");
  if ((info = get_module()))
    {
      info->handshaking = handshaking;
      mod_register(info);
    }
}
#endif

bool		action(void)
{
  printf("Congrats!\n");
  return (true);
}

