/*
** sends_all.c for zappy in /home/gelin_g/Zappy/server_zappy/modules/graph_protocol
** 
** Made by guillaume gelin
** Login   <gelin_g@epitech.net>
** 
** Started on  Wed Jul  6 00:59:13 2011 guillaume gelin
** Last update Fri Jul  8 06:13:18 2011 ramnes
*/

#include	"tserver.h"
#include	"napi.h"
#include	"sends_all.h"

static void    	_sends(void *player, void *msg)
{
  sends((t_fds *)player, (char *)msg);
}

void		sends_all(char *msg)
{
  t_module      *mod;

  mod = get_module_by_name("Graphic Protocol");
  foreach_arg_list(mod->clients, _sends, (void*)msg);
}
