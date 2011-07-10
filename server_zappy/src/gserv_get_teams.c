/*
** gserv_get_teams.c for Zappy in ./server_zappy/src
** 
** Made by di-mar_j
** Login   <di-mar_j@epitech.net>
** 
** Started on  Thu Jun 23 22:12:26 2011 di-mar_j
** Last update Sun Jul 10 23:15:49 2011 di-mar_j
*/

#include	<stdlib.h>
#include	"tserver.h"

extern t_server *gserv;

t_list		*get_teams(void)
{
  return (gserv->team);
}

t_box 		*get_box_at(uint i)
{
  if (i < get_map_max())
    return (NULL);
  return (&(gserv->map.map[i]));
}

t_fds		*get_fds(void)
{
  return (gserv->pool);
}
