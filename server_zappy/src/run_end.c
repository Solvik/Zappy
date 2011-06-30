/*
** run_end.c for  in /Users/Lifely/Developer/project/Zappy/server_zappy
** 
** Made by Julien Di Marco
** Login   <Lifely@epitech.net>
** 
** Started on  Thu Jun 30 05:01:52 2011 Julien Di Marco
** Last update Thu Jun 30 05:01:52 2011 Julien Di Marco
*/

#include	"ztypes.h"
#include	"tserver.h"
#include	"server_zappy.h"

extern t_server	*gserv;

bool		run_end(void)
{
  return (!(gserv->run && get_list_len(gserv->module) > 0 ));
}
