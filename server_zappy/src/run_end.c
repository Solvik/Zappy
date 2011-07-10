/*
** run_end.c for Zappy in ./server_zappy/src
** 
** Made by di-mar_j
** Login   <di-mar_j@epitech.net>
** 
** Started on  Thu Jun 23 22:12:26 2011 di-mar_j
** Last update Sun Jul 10 23:15:49 2011 di-mar_j
*/

#include	"ztypes.h"
#include	"tserver.h"
#include	"server_zappy.h"

extern t_server	*gserv;

bool		run_end(void)
{
  return (!(gserv->run && get_list_len(gserv->module) > 0));
}
