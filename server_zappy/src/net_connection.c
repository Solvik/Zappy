/*
** net_connection.c for  in /Users/Lifely/Developer/project/Zappy/server_zappy/src
** 
** Made by Julien Di Marco
** Login   <Lifely@epitech.net>
** 
** Started on  Mon Jun 20 16:55:35 2011 Julien Di Marco
** Last update Mon Jun 20 16:55:35 2011 Julien Di Marco
*/

#include	<unistd.h>
#include	<stdlib.h>
#include	<string.h>
#include	<stdio.h>
#include	<errno.h>

#include	"error.h"
#include	"client.h"
#include	"network.h"
#include	"tserver.h"

bool	net_port_unique(int port)
{
  fds	tmp;

  if (!gserv_const(false))
    return (false);
  tmp = *get_pool();
  while (tmp)
    {
      if (tmp->s && socket_port(tmp->s) == port)
	return (false);
      tmp = tmp->next;
    }
  return (true);
}

bool	net_bind(uint *port)
{
  int	a;

  a = 0;
  if (!gserv_const(false))
    return (false);
  *port = (int)*port == -1 ? (unsigned)get_port() : *port;
  if (net_port_unique(*port) && !(a = add_socket(get_pool(), *port, 10)))
    return (true);
  if (a == -1)
    syntax_print_error("Connection failed: %s", strerror(errno));
  return (false);
}

static bool	del_pointer(void *a, void *b)
{
  return ((a == b));
}

bool	net_close(fds c)
{
  t_client	*info;

  if (!c)
    return (false);
  if ((info = c->trick))
    {
      if (info->_m)
	del_node_as_arg(&info->_m->clients, del_pointer, c);
      destroy_client(info);
    }
  fds_remove(get_pool(), c, NULL);
  return (true);
}
