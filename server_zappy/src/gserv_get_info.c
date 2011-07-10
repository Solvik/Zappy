/*
** gserv_get_info.c for Zappy in ./server_zappy/src
** 
** Made by di-mar_j
** Login   <di-mar_j@epitech.net>
** 
** Started on  Thu Jun 23 22:12:26 2011 di-mar_j
** Last update Sun Jul 10 23:15:49 2011 di-mar_j
*/

#include	"tserver.h"
#include	"server_zappy.h"

extern t_server *gserv;

int		get_port(void)
{
  return (gserv->info.port);
}

double		get_delay(void)
{
  return (gserv->info.delay);
}

double		get_time(void)
{
  return (gserv->info.time);
}

uint		get_nb_clients(void)
{
  return (gserv->info.nb_clients);
}
