
#include	"map.h"
#include	"zopt.h"
#include	"init.h"
#include	"server_zappy.h"

bool		init(t_map * map, int ac, char *opt[])
{
  t_zopt	optab;

  if (!init_opt(ac, opt, &optab) ||
      !init_network(&optab) ||
      !init_map(map, &optab))
    return (false);
  return (true);
}
