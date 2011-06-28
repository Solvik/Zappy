
#include	<stdio.h>
#include	<string.h>
#include	<strings.h>
#include	<stdlib.h>

#include	"module.h"
#include	"network.h"


bool		test(fds client, char *cmd);

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

void		init_command(t_mod_func *func, char *cmd, void *func)
{
  static int	i = 0;

  func[i].command = strdup(cmd);
  func[i++].action = func;
}

void		init_commands(t_mod_func *func)
{
  init_command(func, "avance",		zappy_avance); /* OK */
  init_command(func, "droite",		zappy_droite); /* OK */
  init_command(func, "gauche",		zappy_gauche);  /* OK */
  init_command(func, "voir",		zappy_voir);
  init_command(func, "inventaire",	zappy_inventaire); /* OK */
  init_command(func, "prend objet",	zappy_prend_objet);
  init_command(func, "pose objet",	zappy_pose_objet);
  init_command(func, "expulse",		zappy_expulse);
  init_command(func, "broadcast texte", zappy_broadcast_texte);
  init_command(func, "incantation",	zappy_incantation);
  init_command(func, "fork",		zappy_fork);
  init_command(func, "connect_nbr",	zappy_connect_nbr);
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

