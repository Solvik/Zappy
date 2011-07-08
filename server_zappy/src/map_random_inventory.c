
#include	<stdlib.h>
#include	<stdio.h>

#include	"tserver.h"
#include	"conf.h"

void		map_random_fill_stones(void)
{
   size_t	i;

  i = 0;
  while (i++ < (((double)map_stones_density / 100.0) * (double)get_map_max()))
    map_random_stone();
}

void		map_random_fill_food(void)
{
  size_t	i;

  i = 0;
  while (i++ < (((double)map_food_density / 100.0) * (double)get_map_max()))
    map_random_food();
}

void		map_random_fill(void)
{
  map_random_fill_stones();
  map_random_fill_food();
}
