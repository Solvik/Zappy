
#include	"tserver.h"
#include	"server_zappy.h"

extern t_server *	gserv;

void		set_port(int port)
{
  gserv->net.port = port;
}
