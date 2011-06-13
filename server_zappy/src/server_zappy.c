
#include	"tserv.h"
#include	"init.h"
#include	"destroy.h"
#include	"server_zappy.h"

bool		server_zappy(char ** opt)
{
  t_serv	s;

  init(&s.map, opt);
  /* do some stuff */
  destroy(&s);
  return (true);
}
