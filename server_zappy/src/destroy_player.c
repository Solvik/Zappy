/*
** destroy_player.c for Zappy in ./server_zappy/src
** 
** Made by di-mar_j
** Login   <di-mar_j@epitech.net>
** 
** Started on  Thu Jun 23 22:12:26 2011 di-mar_j
** Last update Sun Jul 10 23:15:49 2011 di-mar_j
*/

#include        <unistd.h>
#include        <stdlib.h>
#include        <stdio.h>

#include        "tserver.h"
#include        "client.h"

extern t_server *gserv;

static bool             match_pointer(void *data, void *name)
{
  if (!data || !name)
    return (false);
  return ((data == name));
}

void            *destroy_client(t_client *c)
{
  if (!c)
    return (NULL);
  scheduler_destroy(c);
  flood_destroy(c);
  free(c);
  return (NULL);
}

t_player        *player_destroy(t_player *p)
{
  bool		f;

  if (!p || p->food > 0)
    return ((p ? (void*)(p->client = NULL) : NULL));
  f = (p ? p->fork : false);
  event_relative_dispatch("PlayerDied", p, 0);
  if (p->team && del_node_as_arg(&p->team->players, match_pointer, p) && !f)
    p->team->max_conn += 1;
  if (p->egg)
    p->egg = NULL;
  set_box_delplayer(p);
  destroy_list(&p->stones, free);
  free(p);
  return (NULL);
}
