/*
** main.c for  in /Users/Lifely/Developer/project/Zappy/server_zappy/modules/zappy_protocol
**
** Made by Julien Di Marco
** Login   <Lifely@epitech.net>
**
** Started on  Thu Jun 30 03:41:59 2011 Julien Di Marco
** Last update Fri Jul  8 02:17:39 2011 ramnes
*/

#define		_GNU_SOURCE

#include	<stdio.h>
#include	<string.h>
#include	<strings.h>
#include	<stdlib.h>

#include	"napi.h"

#include	"zappy_protocol.h"

t_module	*zappy_module;

#if	defined(NOTSHARED)
__attribute__ ((constructor))
void	init_(void)
{
  t_module	*info;

  if ((info = get_module()))
    {
      info->handshaking = zappy_handshaking;
      info->disconnection = zappy_disconnection;
#if	defined(NDEBUG)
      info->update = zappy_update;
#endif
      info->timer = zappy_timer;
      mod_register(info);
    }
}
#endif

#if	defined(NOTSHARED)
bool		zappy_handshaking(t_fds *c, char *cmd)
#else
bool		handshaking(t_fds *c, char *cmd)
#endif
{
  t_player	*p;

  p = NULL;
  if (c && !c->anounce)
    sends(c, "BIENVENUE");
  if (!c || !cmd)
    return (false);
  if ((!(c->data = new_player(cmd)) || !(p = *(t_player**)c)))
    {
      if ((strcmp(cmd, "GRAPHIC") == 0))
	return (false);
      return (net_close_msg(c, "ko") && false);
    }
  p->client = c;
  sendf(c, "%d", (p->team ? p->team->max_conn : 0));
  sendf(c, "%d %d", (int)get_map_width(), (int)get_map_height());
  event_relative_dispatch("PlayerNew", c, 0);
  return (true);
}

#if	defined(NOTSHARED)
bool		zappy_disconnection(fds c)
#else
bool		disconnection(fds c)
#endif
{
  t_player	*p;

  if (!c || !(p = *(t_player**)c))
    return (true);
  c->data = player_destroy(p);
  return (true);
}
