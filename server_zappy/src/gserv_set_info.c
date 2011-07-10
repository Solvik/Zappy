/*
** gserv_set_info.c for Zappy in ./server_zappy/src
** 
** Made by di-mar_j
** Login   <di-mar_j@epitech.net>
** 
** Started on  Thu Jun 23 22:12:26 2011 di-mar_j
** Last update Sun Jul 10 23:15:49 2011 di-mar_j
*/

#include	<unistd.h>
#include	<stdlib.h>
#include	<stdio.h>

#include	"tserver.h"
#include	"server_zappy.h"

extern t_server	*gserv;

void		set_port(int port)
{
  gserv->info.port = port;
}

void		set_delay(double delay)
{
  if (delay >= 1)
    gserv->info.delay = delay;
}

void		set_time(double time)
{
  if (time >= 1)
    gserv->info.time = time;
}

void		set_nb_clients(uint nb_clients)
{
  gserv->info.nb_clients = nb_clients;
}

void		set_run(bool run)
{
  gserv->run = run;
}
