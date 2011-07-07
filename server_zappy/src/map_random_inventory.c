
#include	<stdlib.h>
#include	<stdio.h>

#include	"tserver.h"
#include	"stone.h"
#include	"conf.h"

static const e_stone stonetab[] =
  {
    LINEMATE,
    DERAUMERE,
    SIBUR,
    MENDIANE,
    PHIRAS,
    THYSTAME
  };

static e_stone	random_stone(void)
{
  static ssize_t	i = -1;

  return (stonetab[(i = (i < (sizeof(stonetab) / sizeof(*stonetab) ?
			      i + 1 : 0)))]);
}

void		map_random_fill_stones(void)
{
   size_t	i;

  i = 0;
  printf("%f\n", (((double)map_stones_density / 100.0) * (double)get_map_max()));
  while (i < (((double)map_stones_density / 100.0) * (double)get_map_max()))
    {
      set_box_addstone(rand() % get_map_width(),
		       rand() % get_map_height(),
		       random_stone(),
		       rand() % map_nb_stones);
      ++i;
    }
}

void		map_random_fill_food(void)
{
  size_t	i;

  i = 0;
  printf("%d * %d  = %f \n", map_food_density, get_map_max(),
	 (((double)map_food_density / 100.0) * (double)get_map_max()));
  while (i < (((double)map_food_density / 100.0) * (double)get_map_max()))
    {
      set_box_addfood(rand() % get_map_width(),
		      rand() % get_map_height(),
		      rand() % map_nb_food);
      ++i;
    }
}

void		map_random_fill(void)
{
  map_random_fill_stones();
  map_random_fill_food();
}
