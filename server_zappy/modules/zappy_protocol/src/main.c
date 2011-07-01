/*
** main.c for  in /Users/Lifely/Developer/project/Zappy/server_zappy/modules/zappy_protocol
** 
** Made by Julien Di Marco
** Login   <Lifely@epitech.net>
** 
** Started on  Thu Jun 30 03:41:59 2011 Julien Di Marco
** Last update Thu Jun 30 03:41:59 2011 Julien Di Marco
*/

#define		_GNU_SOURCE

#include	<stdio.h>
#include	<string.h>
#include	<strings.h>
#include	<stdlib.h>

#include	"napi.h"
#include	"tserver.h"

#include	"module.h"
#include	"network.h"
#include	"player.h"
#include	"zappy_protocol.h"

#if	defined(NOTSHARED)
__attribute__ ((constructor))
void	init_(void)
{
  t_module	*info;

  if ((info = get_module()))
    {
      info->handshaking = handshaking;
      mod_register(info);
    }
}
#endif

bool		handshaking(fds client, char *cmd)
{
  char		*ret;

  if (!client->anounce)
    sends(client, "BIENVENUE");
  if (cmd)
    {
      if ((client->data = new_player(cmd)) == NULL)
	return (false);
      asprintf(&ret, "%d", player_data->id);
      sends(client, ret);
      if (ret)
	free(ret);
      asprintf(&ret, "%d %d", player_data->x, player_data->y);
      sends(client, ret);
      if (ret)
	free(ret);
      return (true);
    }
  return (false);
}
