
#include	"tserver.h"
#include	"server_zappy.h"

extern t_server *	gserv;

int		get_port(void)
{
  return (gserv->net.port);
}
