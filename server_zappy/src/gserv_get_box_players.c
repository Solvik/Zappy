/*
** gserv_get_box_players.c for Zappy in ./server_zappy/src
** 
** Made by di-mar_j
** Login   <di-mar_j@epitech.net>
** 
** Started on  Thu Jun 23 22:12:26 2011 di-mar_j
** Last update Sun Jul 10 23:15:49 2011 di-mar_j
*/

#include		<stdlib.h>
#include		"tserver.h"
#include		"server_zappy.h"

extern t_server 	*gserv;

t_list			*get_box_players(uint x, uint y)
{
  t_box 		*box;

  if (!(box = get_box(x, y)))
    return (false);
  return (box->players);
}
