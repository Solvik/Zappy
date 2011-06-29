
#include		<stdlib.h>
#include		"team.h"
#include		"tserver.h"

extern t_server *	gserv;

static void		delete_player(t_player * player)
{
  /* delete stones */
  destroy_list(&player->stones, free);
  free(player);
}

static bool		match_player(void * data, void * arg)
{
  return (data == arg);
}

void			setbox_del_player(t_player * player)
{
  t_team *		team;
  t_box *		box;

  /* delete on teams */
  if (!(team = get_team_of_player(player)))
    return ;
  del_node_as_arg(&team->players, match_player, player);
  /* delete on map */
  if (!(box = get_box(player->x, player->y)))
    return ;
  del_node_as_arg(&box->players, match_player, player);
  /* delete player */
  delete_player(player);
}

