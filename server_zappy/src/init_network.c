/*
** init_network.c for  in /Users/Lifely/Developer/project/Zappy/server_zappy
** 
** Made by Julien Di Marco
** Login   <Lifely@epitech.net>
** 
** Started on  Thu Jun 30 05:04:52 2011 Julien Di Marco
** Last update Thu Jun 30 05:04:52 2011 Julien Di Marco
*/

#include	<stdio.h>

#include	"zopt.h"
#include	"module.h"
#include	"net.h"
#include	"tserver.h"
#include	"server_zappy.h"

static void	net_init(void *data)
{
  if (!data)
    return ;
  net_bind(&((t_module*)data)->port);
}

bool		init_network(t_zopt *optab)
{
  (void)optab;
  set_port(optab->port);
  foreach_list(get_modules(), net_init);
  return (true);
}
