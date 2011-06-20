
#include	<stdio.h>

#include	"dbg.h"
#include	"run.h"
#include	"module.h"
#include	"tserver.h"
#include	"server_zappy.h"

extern t_server	*gserv;

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
  dbg_show_map();
  foreach_list(get_modules(), action_module);
  while (!run_end())
    {
      pool(&gserv->pool);
    }
  return (true);
}
