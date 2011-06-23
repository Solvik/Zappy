
#include	"map.h"
#include	"zopt.h"
#include	"init.h"
#include	"tserver.h"
#include	"server_zappy.h"

bool		init(int opt_size, char ** opt)
{
  t_zopt	optab;

  gserv_const(true);
  if (!init_opt(opt_size, opt, &optab) ||
      !init_map(&optab) ||
      !init_network(&optab) ||
      !init_modules(&optab))
    return (false);
  return (true);
}
