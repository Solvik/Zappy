/*
** mod_handshaking.c for  in /home/di-mar_j/git/Zappy/server_zappy
** 
** Made by julien di-marco
** Login   <di-mar_j@epitech.net>
** 
** Started on  Tue Jun 28 20:18:11 2011 julien di-marco
** Last update Tue Jun 28 20:18:11 2011 julien di-marco
*/

#include	<unistd.h>
#include	<stdlib.h>
#include	<stdio.h>

#include	"error.h"
#include	"tserver.h"
#include	"module.h"
#include	"client.h"

static bool		mod_handshaking(void *elem, void *arg)
{
  t_module	*module;
  fds		client;

  if (!(module = elem) || !(client = arg) || !client->trick)
    return (true);
  if ((int)module->port != client->port)
    return (false);
  if (module->handshaking &&
      module->handshaking(client, ((t_client*)client->trick)->command))
    {
      print_debug("New client on [%s] < -- > [%d].",
		  module->name, socket_fd(client->s));
      ((t_client*)client->trick)->_m = module;
      put_in_list(&module->clients, client);
      if ((int)module->antiflood > 0)
	{
	  ((t_client*)client->trick)->flood.array = \
	    calloc(module->antiflood  + 1, sizeof(char*));
	  ((t_client*)client->trick)->flood.size = module->antiflood;
	}
      return (true);
    }
  return (false);
}

bool	       mod_discovery(fds client, char **s)
{
  char		*cmd;
  t_client	*info;

  cmd = (s ? *s : NULL);
  if (!client)
    return (false);
  if (!(info = client->trick))
    {
      if (!(client->trick = calloc(1, sizeof(*info))))
	return (false);
      else
	info = client->trick;
    }
  ((t_client*)client->trick)->command = cmd;
  foreach_arg_stop_list(get_modules(), mod_handshaking, client);
  ((t_client*)client->trick)->command = NULL;
  free(cmd);
  if (s)
    *s = NULL;
  return (true);
}
