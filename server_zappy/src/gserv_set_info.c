/*
** gserv_set_network.c for  in /Users/Lifely/Developer/project/Zappy/server_zappy
** 
** Made by Julien Di Marco
** Login   <Lifely@epitech.net>
** 
** Started on  Thu Jun 30 05:05:08 2011 Julien Di Marco
** Last update Thu Jun 30 05:05:08 2011 Julien Di Marco
*/

#include	"tserver.h"
#include	"server_zappy.h"

extern t_server	*gserv;

void		set_port(int port)
{
  gserv->info.port = port;
}

void		set_delay(double delay)
{
  gserv->info.delay = delay;
}

void		set_time(double time)
{
  gserv->info.time = time;
}
