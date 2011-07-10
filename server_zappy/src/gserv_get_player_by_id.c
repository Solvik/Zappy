/*
** gserv_get_player_by_id.c for Zappy in ./server_zappy/src
** 
** Made by di-mar_j
** Login   <di-mar_j@epitech.net>
** 
** Started on  Thu Jun 23 22:12:26 2011 di-mar_j
** Last update Sun Jul 10 23:15:49 2011 di-mar_j
*/

#include	<stdlib.h>
#include	"tserver.h"

extern t_server *	gserv;

typedef		struct
{
  t_player *	player;
  uint		id;
}		t_playerid;

static bool	match_player(void * player, void * playerid)
{
  if (((t_player *)player)->id == ((t_playerid *)playerid)->id)
    {
      ((t_playerid *)playerid)->player = ((t_player *)player);
      return (true);
    }
  return (false);
}

static bool	match_team(void * team, void * playerid)
{
  return (get_data_as_arg(((t_team *)team)->players, match_player,
			  playerid));
}

t_player *	get_player_by_id(uint id)
{
  t_playerid	playerid;

  playerid.player = NULL;
  playerid.id = id;
  foreach_arg_stop_list(gserv->team, match_team, &playerid);
  return (playerid.player);
}
