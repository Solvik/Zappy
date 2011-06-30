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
      if (tmp->s && tmp->s->port == port)
	return (false);
      tmp = tmp->next;
    }
  return (true);
}

bool	net_bind(uint *port)
{
  if (!gserv_const(false))
    return (false);
  *port = (int)*port == -1 ? (unsigned)get_port() : *port;
  if (net_port_unique(*port) && add_socket(get_pool(), *port, 10))
    return (true);
  return (false);
}
