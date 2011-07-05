/*
** gserv_get_module_by_name.c for  in /Users/sebastienblot/git/Zappy/server_zappy/modules/zappy_protocol
**
** Made by Sebastien Blot
** Login   <sebastienblot@epitech.net>
**
** Started on  Mon Jul  4 16:40:24 2011 Sebastien Blot
** Last update Mon Jul  4 19:45:06 2011 Sebastien Blot
*/

#include	<stdlib.h>
#include	<string.h>
#include	"tserver.h"
#include	"server_zappy.h"

extern t_server *gserv;

static bool match_name(void *data, void *arg)
{
  if (!strcasecmp((char *)arg, ((t_module *)(data))->name))
	return (true);
  return (false);
}

t_module *get_module_by_name(char *name)
{
  t_module *ret;

  ret = get_data_as_arg(gserv->module, match_name, name);
  return (ret);
}
