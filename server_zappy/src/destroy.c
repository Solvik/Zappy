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

extern t_server	*gserv;

void		destroy(void)
{
  if (gserv)
    {
      destroy_list(&gserv->names.modules, free);
      destroy_list(&gserv->names.teams, free);
    }
  free(get_map());
}
