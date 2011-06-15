
#include	"dbg.h"
#include	"run.h"
#include	"server_zappy.h"

bool		run(void)
{
  while (!run_end())
    {
      dbg_show_map();
    }
  return (true);
}
