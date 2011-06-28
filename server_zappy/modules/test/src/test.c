
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
  module->name = strdup("test");
  module->delim = strdup("\r\n");
  module->port = -1;
  module->antiflood = 10;
  module->clients = NULL;
  module->functions[0].command = strdup("test");
  module->functions[0].action = test;
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

