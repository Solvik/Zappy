/*
** connect_nbr.c for Zappy in ./server_zappy/modules/zappy_protocol/src
** 
** Made by di-mar_j
** Login   <di-mar_j@epitech.net>
** 
** Started on  Thu Jun 23 22:12:26 2011 di-mar_j
** Last update Sun Jul 10 23:15:49 2011 di-mar_j
*/

#define		_GNU_SOURCE
#include	<stdlib.h>
#include	<stdio.h>

#include	"napi.h"

int		zappy_connect_nbr(t_fds *c, char *_)
{
  t_player	*p;

  (void)_;
  if (!c || !(p = *(t_player**)c) || !p->team)
    return (false);
  sendf(c, "%d", p->team->max_conn);
  return (true);
}
