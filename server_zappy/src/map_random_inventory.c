
#include	<stdlib.h>
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
  return (stonetab[rand() % (sizeof(stonetab) / sizeof(*stonetab))]);
}

void		map_random_fill_stones(void)
{
   size_t	i;

  i = 0;
  while (i < (get_map_max() / 100 * map_stones_density))
    {
      set_box_addstone(rand() % get_map_width(),
		       rand() % get_map_height(),
		       random_stone(),
		       map_nb_stones);
      ++i;
    } 
}

void		map_random_fill_food(void)
{
  size_t	i;

  i = 0;
  while (i < (get_map_max() / 100 * map_food_density))
    {
      set_box_addfood(rand() % get_map_width(),
		      rand() % get_map_height(),
		      map_nb_food);
      ++i;
    }  
}

void		map_random_fill(void)
{
  map_random_fill_stones();
  map_random_fill_food();
}
