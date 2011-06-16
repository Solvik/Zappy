
#include	"ztypes.h"
#include	"server_zappy.h"

bool		run_end(void)
{
  static uint tmp = 0;

  ++tmp;
  return (!(tmp <= 2));
}
