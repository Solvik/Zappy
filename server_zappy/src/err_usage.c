
#include	<time.h>
#include	<stdio.h>
#include	"error.h"
#include	"conf.h"

bool		usage(char * path)
{
  fprintf(stderr, "\nusage: %s -n team1 team2...\n\
         [-s seed] [-t delay]\n\
         [-c nb_clients] [-p port] [-r time]\n\
         [-w width] [-x width] [-h height] [-y height]\n\
         [-m module1 module2...] [-u]\n\
\n\
Default values :\n\
seed            = current local timestamp\n\
-> Seed is the random initialisation value.\n\
port            = %u\n\
-> Server port\n\
nb clients      = %u\n\
-> Maximum clients by team\n\
delay           = %.2f\n\
-> Value of time t\n\
time            = %.2f second\n\
-> Reference time\n\
width           = %u\n\
height          = %u\n\
-> Map size\n\
\n\
-m is the list of modules to load (.so files).\n\
-u print this usage/help\n\n\
", path, default_port, default_nb_clients, default_delay,
	  default_time, default_width, default_height);
    return (false);
}
