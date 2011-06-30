
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

/*
**
** avance : OK
** droite : OK
** gauche : OK
** voir : OK
** inventaire : OK
** expulse : OK
** prend
** pose
** broadcast
** incantation
** fork
** connect_nbr
**
*/

void		init_commands(t_mod_func *func)
{
  add_command(func, "avance",		zappy_avance);
  add_command(func, "droite",		zappy_droite);
  add_command(func, "gauche",		zappy_gauche);
  add_command(func, "voir",		zappy_voir);
  add_command(func, "inventaire",	zappy_inventaire);
  add_command(func, "expulse",		zappy_expulse);
  add_command(func, "prend",		zappy_prend);
  add_command(func, "pose",		zappy_pose);
  add_command(func, "broadcast",	zappy_broadcast);
  add_command(func, "incantation",	zappy_incantation);
  add_command(func, "fork",		zappy_fork);
  add_command(func, "connect_nbr",	zappy_connect_nbr);
}

t_module	*get_module(void)
{
  t_module	*module;

  if (!(module = malloc(sizeof(*module) + sizeof(t_mod_func) * 5)))
    return (NULL);
  bzero(module, sizeof(*module) + sizeof(t_mod_func) * 5);
  module->name = strdup("Zappy Protocol");
  module->delim = strdup("\r\n");
  module->port = -1;
  module->antiflood = 10;
  module->clients = NULL;
  init_commands(module->functions);
  return (module);
}

bool		test(fds client, char *cmd)
{
  (void)client;
  printf("WORKING : [%s]\n", cmd);
  return (true);
}

bool		handshaking(fds client, char *cmd)
{
  char		*ret;

  if (!client->anounce)
    sends(client, "BIENVENUE");
  if (cmd)
    {
      if ((client->data = new_player()) == NULL ||
	  (setbox_add_player(client->data,
			     cmd,
			     rand() % get_map_width(),
			     rand() % get_map_height())) == false)
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

#if	defined(NOTSHARED)
__attribute__ ((constructor))
void	init_(void)
{
  t_module	*info;

  printf("Should really work !\n");
  if ((info = get_module()))
    {
      info->handshaking = handshaking;
      mod_register(info);
    }
}
#endif

bool		action(void)
{
  printf("Congrats!\n");
  return (true);
}

