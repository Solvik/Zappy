/*
** destroy.c for  in /Users/Lifely/Developer/project/Zappy/server_zappy
** 
** Made by Julien Di Marco
** Login   <Lifely@epitech.net>
** 
** Started on  Thu Jun 30 05:06:03 2011 Julien Di Marco
** Last update Sat Jul  9 22:28:20 2011 guillaume gelin
*/

#include	<unistd.h>
#include	<stdlib.h>

#include	"tserver.h"
#include	"client.h"

extern t_server	*gserv;

static bool             match_pointer(void *data, void *name)
{
  if (!data || !name)
    return (false);
  return ((data == name));
}

void		*destroy_client(t_client *c)
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
  if (!p || p->food > 0)
    return ((p ? (void*)(p->client = NULL) : NULL));
  event_relative_dispatch("PlayerDied", p, 0);
  if (p->team && del_node_as_arg(&p->team->players, match_pointer, p))
    p->team->max_conn += 1;
  set_box_delplayer(p);
  destroy_list(&p->stones, free);
  free(p);
  return (NULL);
}

void		destroy(void)
{
  free(get_map());
}
