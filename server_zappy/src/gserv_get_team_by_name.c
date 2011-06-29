
#include		<string.h>
#include		"tserver.h"

extern t_server *	gserv;

bool			match_team(void * data, void * name)
{
  return (!(strcmp(((t_team *)data)->name, (char *)name)));
}

t_team *		get_team_by_name(char * name)
{
  return (get_data_as_arg(gserv->team, match_team, name));
}
