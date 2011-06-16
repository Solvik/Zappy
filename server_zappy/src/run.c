
#include	"dbg.h"
#include	"run.h"
#include	"module.h"
#include	"tserver.h"
#include	"server_zappy.h"

static void	action_module(void * data)
{
  ((t_module *)data)->functions.action();
}

bool		run(void)
{
  while (!run_end())
    {
      dbg_show_map();
      foreach_list(get_modules(), action_module);
    }
  return (true);
}
