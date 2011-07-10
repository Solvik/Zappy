/*
** graph_player.c for Zappy in ./server_zappy/modules/graph_protocol/src
** 
** Made by di-mar_j
** Login   <di-mar_j@epitech.net>
** 
** Started on  Thu Jun 23 22:12:26 2011 di-mar_j
** Last update Sun Jul 10 23:15:49 2011 di-mar_j
*/

#include	<stdlib.h>
#include	<string.h>
#include	"graph_player.h"
#include	"tserver.h"

/* ppo numero_joueur X Y orientation */
bool		graph_ppo(t_fds *client, char *cmd)
{
  char		*id;
  unsigned int	x;
  unsigned int	y;
  unsigned int	o;

  strtok(cmd, " ");
  id = strtok(NULL, " ");
  if (!id || get_player_pos(atoi(id), &x, &y, &o) == false)
    {
      sends(client, "sbp");
      return (false);
    }
  sendf(client, "ppo %s %d %d %d", id, x, y, o);
  return (true);
}

/* plv numero_joueur niveau */
bool		graph_plv(t_fds *client, char *cmd)
{
  char		*id;
  int		level;

  strtok(cmd, " ");
  id = strtok(NULL, " ");
  if (!id || (level = get_player_level(atoi(id))) == 0)
    {
      sends(client, "sbp");
      return (false);
    }
  sendf(client, "plv %s %d", id, level);
  return (true);
}

/* pin numero_joueur X Y quantite_pierre quantite_bouffe */
bool		graph_pin(t_fds *client, char *cmd)
{
  char		*id;
  unsigned int	x;
  unsigned int	y;

  strtok(cmd, " ");
  id = strtok(NULL, " ");
  if (!id || get_player_pos(atoi(id), &x, &y, NULL) == false)
    {
      sends(client, "sbp");
      return (false);
    }
  sendf(client, "pin %s %d %d %d %d %d %d %d %d %d", id, x, y,
	get_player_food(atoi(id)),
	get_player_nbstones(atoi(id), LINEMATE),
	get_player_nbstones(atoi(id), DERAUMERE),
	get_player_nbstones(atoi(id), SIBUR),
	get_player_nbstones(atoi(id), MENDIANE),
	get_player_nbstones(atoi(id), PHIRAS),
	get_player_nbstones(atoi(id), THYSTAME));
  return (true);
}
