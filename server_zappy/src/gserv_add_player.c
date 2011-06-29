
#include		<stdlib.h>
#include		<string.h>
#include		"tserver.h"
#include		"player.h"
#include		"team.h"
#include		"server_zappy.h"

extern t_server *	gserv;

static bool		match_team(void * data, void * name)
{
  return (!(strcmp(((t_team *)data)->name, (char *)name)));
}

static t_team *		add_team(char * name)
{
  t_team *		team;

  if (!(team = malloc(sizeof(*team))))
    return (NULL);
  team->name = strdup(name);
  team->players = NULL;
  if (!(put_in_list(&gserv->team, team)))
    return (NULL);
  return (team);
}

bool			add_player(t_player * player, char * name)
{
  t_team *		team;

  if ((!(team = get_data_as_arg(gserv->team, match_team, name)) &&
       !(team = add_team(name))) ||
      (!(put_in_list(&team->players, player))))
    return (false);
  return (true);
}
