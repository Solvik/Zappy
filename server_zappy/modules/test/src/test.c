
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
  module->name = strdup("test");
  module->delim = strdup("\r\n");
  module->port = -1;
  module->antiflood = 10;
  module->clients = NULL;
  return (module);
}

#if	defined(NOTSHARED)
__attribute__ ((constructor))
void	init_(void)
{
  printf("Should really work !\n");
  mod_register(get_module());
}
#endif

bool		action(void)
{
  printf("Congrats!\n");
  return (true);
}
