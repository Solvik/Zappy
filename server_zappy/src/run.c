
#include	<stdio.h>

#include	"dbg.h"
#include	"run.h"
#include	"module.h"
#include	"tserver.h"
#include	"server_zappy.h"

static void	action_module(void * data)
{
  printf("Loaded module: %s\n", ((t_module *)data)->name);
  if (!data)
    printf("Empty Chunk\n");
  if (((t_module *)data)->functions.action)
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
