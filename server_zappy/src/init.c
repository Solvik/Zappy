
#include	"map.h"
#include	"zopt.h"
#include	"init.h"
#include	"server_zappy.h"

bool		init(t_map * map, char ** opt)
{
  t_zopt	optab;

  if (!init_opt(opt, map, &optab) ||
      !init_network(&optab) ||
      !init_map(map))
    return (false);
  return (true);
}
