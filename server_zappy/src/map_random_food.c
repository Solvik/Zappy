
#include	<stdlib.h>
#include	"tserver.h"
#include	"conf.h"

void		map_random_food(void)
{
  set_box_addfood(rand() % get_map_width(),
		  rand() % get_map_height(),
		  rand() % map_nb_food);
}
