
#include	<stdlib.h>
#include	"server_zappy.h"

int		main(__attribute__((unused))int argc, char ** argv)
{
  return (server_zappy(argv) ? EXIT_SUCCESS : EXIT_FAILURE);
}
