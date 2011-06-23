
#include	"tserver.h"

extern t_server *	gserv;

fds *		get_pool(void)
{
  return (&(gserv->pool));
}

