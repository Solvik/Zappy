/*
** gserv_get.c for  in /Users/Lifely/Developer/project/Zappy/server_zappy
** 
** Made by Julien Di Marco
** Login   <Lifely@epitech.net>
** 
** Started on  Thu Jun 30 05:05:36 2011 Julien Di Marco
** Last update Thu Jun 30 05:05:36 2011 Julien Di Marco
*/

#include	"tserver.h"

extern t_server *	gserv;

fds *		get_pool(void)
{
  return (&(gserv->pool));
}

