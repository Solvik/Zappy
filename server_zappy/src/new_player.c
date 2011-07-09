/*
** new_player.c for  in /home/di-mar_j/git/Zappy/server_zappy
** 
** Made by julien di-marco
** Login   <di-mar_j@epitech.net>
** 
** Started on  Fri Jul  8 16:55:38 2011 julien di-marco
** Last update Fri Jul  8 16:55:38 2011 julien di-marco
*/

#include	<unistd.h>
#include        <stdlib.h>
#include        <string.h>
#include	<stdio.h>
#include        <time.h>

#include        "tserver.h"
#include        "conf.h"
#include        "player.h"

extern t_server *gserv;

static t_player *init_player(t_team *team)
{
  static uint   id = 0;
  t_player      *player;

  if (!team || !(player = calloc(1, sizeof(*player))))
    return (NULL);
  player->id = id++;
  player->level = default_level;
  player->food = default_life;
  player->foodt = default_life;
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

static bool             match_pointer(void *data, void *name)
{
  if (!data || !name)
    return (false);
  return ((data == name));
}

t_player        *player_destroy(t_player *p)
{
  if (!p || p->food > 0)
    return ((p ? (void*)(p->client = NULL) : NULL));
  if (p->team && del_node_as_arg(&p->team->players, match_pointer, p))
    p->team->max_conn += 1;
  set_box_delplayer(p);
  destroy_list(&p->stones, free);
  free(p);
  return (NULL);
}

static bool	find_ghost(void *elem)
{
  t_player	*p;

  if (!(p = (t_player*)elem))
    return (false);
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
    return (player_destroy(player));
  return (player);
}
