/*
** init_network.c for Zappy in ./server_zappy/src
** 
** Made by di-mar_j
** Login   <di-mar_j@epitech.net>
** 
** Started on  Thu Jun 23 22:12:26 2011 di-mar_j
** Last update Sun Jul 10 23:15:49 2011 di-mar_j
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
  set_delay(optab->delay);
  set_time(optab->time);
  set_nb_clients(optab->nb_clients);
  foreach_list(get_modules(), net_init);
  return (true);
}
