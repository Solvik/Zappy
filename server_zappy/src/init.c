
#include	"map.h"
#include	"zopt.h"
#include	"init.h"
#include	"tserver.h"
#include	"server_zappy.h"

extern t_server	*gserv;

bool		init(int opt_size, char ** opt)
{
  gserv_const(true);
  if (!init_opt(opt_size, opt, &gserv->options) ||
      !init_map(&gserv->options) ||
      !init_modules(&gserv->options) ||
      !init_network(&gserv->options))
    return (false);
  return (true);
}
