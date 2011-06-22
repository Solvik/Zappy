
#include	<stdio.h>

#include	"zopt.h"
#include	"module.h"
#include	"net.h"
#include	"tserver.h"
#include	"server_zappy.h"

static void	net_init(void *data)
{
  if (!data)
    return ;
  net_bind(&((t_module*)data)->port);
}

bool		init_network(t_zopt * optab)
{
  (void)optab;
  foreach_list(get_modules(), net_init);
  return (true);
}
