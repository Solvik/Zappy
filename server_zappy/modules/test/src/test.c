
#include	<stdio.h>
#include	<string.h>
#include	<strings.h>
#include	<stdlib.h>

#include	"module.h"
#include	"network.h"

t_module	*get_module(void)
{
  t_module	*module;

  if (!(module = malloc(sizeof(*module))))
    return (NULL);
  bzero(module, sizeof(*module));
  module->name = strdup("test");
  module->delim = strdup("\r\n");
  module->port = -1;
  module->antiflood = 10;
  module->clients = NULL;
  return (module);
}

bool		handshaking(fds client)
{
  (void)client;
  printf("Hello hello\n");
  return (true);
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

