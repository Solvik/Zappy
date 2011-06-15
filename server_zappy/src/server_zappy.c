
#include	"tserver.h"
#include	"init.h"
#include	"net.h"
#include	"destroy.h"
#include	"server_zappy.h"

t_server *	gserv;

bool		server_zappy(int opt_size, char ** opt)
{
  t_server	s;

  gserv = &s;
  if (!init(opt_size, opt) ||
      !net_wait_clients() ||
      !run())
    return (false);
  destroy(&s);
  return (true);
}
