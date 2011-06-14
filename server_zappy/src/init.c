
#include	"map.h"
#include	"zopt.h"
#include	"init.h"
#include	"server_zappy.h"

bool		init(int opt_size, char ** opt)
{
  t_zopt	optab;

  if (!init_opt(opt_size, opt, &optab) ||
      !init_network(&optab) ||
      !init_map(&optab))
    return (false);
  return (true);
}
