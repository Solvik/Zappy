/*
** destroy.c for  in /Users/Lifely/Developer/project/Zappy/server_zappy
** 
** Made by Julien Di Marco
** Login   <Lifely@epitech.net>
** 
** Started on  Thu Jun 30 05:06:03 2011 Julien Di Marco
** Last update Thu Jun 30 05:06:03 2011 Julien Di Marco
*/

#include	<unistd.h>
#include	<stdlib.h>

#include	"tserver.h"
#include	"client.h"

extern t_server	*gserv;

void		*destroy_client(t_client *c)
{
  if (!c)
    return (NULL);
  scheduler_destroy(c);
  flood_destroy(c);
  free(c);
  return (NULL);
}

void		destroy(void)
{
  free(get_map());
}
