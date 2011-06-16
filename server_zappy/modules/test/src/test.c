
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
  module->id = 0;
  module->port = 42;
  module->antiflood = 10;
  module->delim = strdup("\r\n");
  module->clients = NULL;
  return (module);
}

bool		action(void)
{
  printf("Congrats!\n");
  return (true);
}
