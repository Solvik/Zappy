/*
** gserv_get_module_by_name.c for Zappy in ./server_zappy/src
** 
** Made by di-mar_j
** Login   <di-mar_j@epitech.net>
** 
** Started on  Thu Jun 23 22:12:26 2011 di-mar_j
** Last update Sun Jul 10 23:15:49 2011 di-mar_j
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
