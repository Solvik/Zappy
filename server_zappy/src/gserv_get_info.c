/*
** gserv_get_network.c for  in /Users/Lifely/Developer/project/Zappy/server_zappy
** 
** Made by Julien Di Marco
** Login   <Lifely@epitech.net>
** 
** Started on  Thu Jun 30 05:05:31 2011 Julien Di Marco
** Last update Thu Jun 30 05:05:31 2011 Julien Di Marco
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
