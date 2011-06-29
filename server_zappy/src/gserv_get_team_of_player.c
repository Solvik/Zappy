
#include	<string.h>
#include	"tserver.h"

extern t_server *	gserv;

static bool	match_player(void * data, void * arg)
{
  return (data == arg);
}

static bool	match_team(void * data, void * arg)
{
  return (get_data_as_arg(((t_team *)data)->players,
			  match_player, arg));
}

t_team *	get_team_of_player(t_player * player)
{
  return (get_data_as_arg(gserv->team, match_team, player));
}
