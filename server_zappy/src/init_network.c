
#include	<stdio.h>

#include	"zopt.h"
#include	"server_zappy.h"

bool		init_network(t_zopt * optab)
{
  printf("Port : %d\n", optab->port);
  return (true);
}
