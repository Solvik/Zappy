/*
** voir_dir.c for  in /Users/Lifely/Developer/project/Zappy/server_zappy/modules/zappy_protocol
** 
** Made by Julien Di Marco
** Login   <Lifely@epitech.net>
** 
** Started on  Thu Jun 30 04:07:44 2011 Julien Di Marco
** Last update Thu Jun 30 04:07:44 2011 Julien Di Marco
*/

#include <stdlib.h>
#include <string.h>

#include "tserver.h"

#include "player.h"
#include "voir.h"
#include "map.h"
#include "server_zappy.h"

char     *concat(char *msg, char *concat);
int	_voir_ne(char **ret, int i, int x, int pos);
int	_voir_ns(char **ret, int i, int x, int pos);

void		check_case(int _, char **ret)
{
  t_box		*map;
  int		i;
  int		j;

  (void)_;
  map = get_map();
  i = 0;
  while (i < get_list_len(map[i].players))
    {
      *ret = concat(*ret, " joueur");
      i += 1;
    }
  i = 0;
  while (i < (int)map[i].food)
    {
      *ret = concat(*ret, " nourriture");
      i += 1;
    }
  i = 0;
  while (i < get_list_len(map[i].stones))
    {
      j = -1;
      while (++j < size_stone)
	*ret = concat(*ret, gl_ressource_name[j].str);
      i += 1;
    }
}

void	zappy_voir_north(int pos, int step, char **ret)
{
  int		angle_y;
  int		angle_x;
  int		check;
  int		i;

  angle_y = 0;
  angle_x = 1;
  i = pos;
  while (step != 0)
    {
      check_case(i, ret);
      check = _voir_ns(ret, i, angle_x, pos);
      if ((i -= get_map_width()) < 0)
	i += get_map_max();
      step--;
      angle_x = ++angle_y;
    }
}

void	zappy_voir_south(int pos, int step, char **ret)
{
  int		angle_y;
  int		angle_x;
  int		check;
  int		i;

  angle_x = 1;
  angle_y = 0;
  i = pos;
  while (step != 0)
    {
      check_case(i, ret);
      check = _voir_ns(ret, i, angle_x, pos);
      if ((i += get_map_width()) > (int)get_map_max())
	i -= get_map_max();
      step--;
      angle_x = ++angle_y;
    }
}

void	zappy_voir_west(int pos, int step, char **ret)
{
  int		check;
  int		angle_y;
  int		angle_x;
  int		i;

  angle_x = 1;
  angle_y = 0;
  i = pos;
  while (step != 0)
    {
      check_case(i, ret);
      check = _voir_ne(ret, i, angle_x, pos);
      if (((i -= 1) / get_map_width()) != (pos / get_map_width()))
	i += get_map_width();
      step--;
      angle_x = ++angle_y;
    }
}

void	zappy_voir_east(int pos, int step, char **ret)
{
  int		check;
  int		angle_y;
  int		angle_x;
  int		i;

  angle_x = 1;
  angle_y = 0;
  i = pos;
  while (step != 0)
    {
      check_case(i, ret);
      printf("Hella \n");
      check = _voir_ne(ret, i, angle_x, pos);
      printf("Hello \n");
      if (((i += 1) / get_map_width()) != (pos / get_map_width()))
	i -= get_map_width();
      step--;
      angle_x = ++angle_y;
    }
}

