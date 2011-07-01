
#include	<string.h>
#include	"tserver.h"

extern t_server *	gserv;

bool		match_name(void * str1, void * str2)
{
  return (!(strcmp((char *)str1, (char *)str2)));
}

bool		available_modules(char * name)
{
  return (get_data_as_arg(gserv->names.modules, match_name, name));
}

bool		available_teams(char * name)
{
  return (get_data_as_arg(gserv->names.teams, match_name, name));
}

