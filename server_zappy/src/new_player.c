/*
** new_player.c for Zappy in ./server_zappy/src
** 
** Made by di-mar_j
** Login   <di-mar_j@epitech.net>
** 
** Started on  Thu Jun 23 22:12:26 2011 di-mar_j
** Last update Sun Jul 10 23:15:49 2011 di-mar_j
*/

#include	<unistd.h>
#include        <stdlib.h>
#include        <string.h>
#include	<stdio.h>
#include        <time.h>

#include	"time_.h"
#include        "tserver.h"
#include        "conf.h"
#include        "player.h"

extern t_server *gserv;

t_player *init_player(t_team *team)
{
  static uint   id = 0;
  t_player      *player;

  if (!team || !(player = calloc(1, sizeof(*player))))
    return (NULL);
  player->id = id++;
  player->level = default_level;
  player->food = default_life;
  player->foodt = default_life;
  player->foodlt = time_();
  player->x = rand() % get_map_width();
  player->y = rand() % get_map_height();
  player->direction = rand() % (WEST + 1);
  player->team = team;
  team->max_conn -= 1;
  return (player);
}

static bool             match_team(void *data, void *name)
{
  if (!data || !name)
    return (false);
  return ((strcmp(((t_team *)data)->name, (char *)name) == 0));
}

static bool	find_ghost(void *elem)
{
  t_player	*p;

  if (!(p = (t_player*)elem))
    return (false);
  if (p->fork)
    event_relative_dispatch("EggBound", p, 0);
  return ((p->client ? false : true));
}

t_player *      new_player(char * teamname)
{
  t_team	*team;
  t_player      *player;

  player = NULL;
  if (!teamname || !gserv_const(false) || !gserv ||
      !(team = get_data_as_arg(gserv->team, match_team, teamname)) ||
      !((player = get_data_as(team->players, find_ghost)) ||
	((team->max_conn > 0) && (player = init_player(team)) &&
	 put_in_list(&team->players, player) &&
	 set_box_addplayer(player, player->x, player->y))))
    return (player ? player_destroy(player) : NULL);
  return (player);
}
