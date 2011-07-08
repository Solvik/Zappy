/*
** voir.c for  in /home/solvik/tek2/proj/Zappy/server_zappy/src
**
** Made by solvik blum
** Login   <blum_s@epitech.net>
**
** Started on  Mon Jun 13 12:46:13 2011 solvik blum
** Last update Sun Jul  3 22:36:21 2011 solvik blum
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
