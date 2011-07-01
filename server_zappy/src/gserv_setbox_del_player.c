/*
** gserv_del_player.c for  in /Users/Lifely/Developer/project/Zappy/server_zappy
** 
** Made by Julien Di Marco
** Login   <Lifely@epitech.net>
** 
** Started on  Thu Jun 30 05:05:43 2011 Julien Di Marco
** Last update Thu Jun 30 05:05:43 2011 Julien Di Marco
*/

#include		<stdlib.h>
#include		"team.h"
#include		"tserver.h"

extern t_server		*gserv;

/*
** delete stones - l: 23
*/

static void		delete_player(t_player *player)
{
  destroy_list(&player->stones, free);
  free(player);
}

static bool		match_player(void *data, void *arg)
{
  return (data == arg);
}

/*
** delete on teams l :40
** delete on map   l :45
** delete player   l :50
*/

void			setbox_del_player(t_player *player)
{
  t_team 		*team;
  t_box 		*box;

  if (!(team = get_team_of_player(player)))
    return ;
  del_node_as_arg(&team->players, match_player, player);

  if (!(box = get_box(player->x, player->y)))
    return ;
  del_node_as_arg(&box->players, match_player, player);

  delete_player(player);
}

