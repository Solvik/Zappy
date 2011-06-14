
#include	<stdlib.h>
#include	"server_zappy.h"

int		main(int argc, char *argv[])
{
  return (server_zappy(argc, argv) ? EXIT_SUCCESS : EXIT_FAILURE);
}
