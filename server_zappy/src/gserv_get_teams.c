
#include	"tserver.h"

extern t_server *	gserv;

t_list *	get_teams(void)
{
  return (gserv->team);
}
