/*
** voir.c for  in /home/solvik/tek2/proj/Zappy/server_zappy/src
**
** Made by solvik blum
** Login   <blum_s@epitech.net>
**
** Started on  Mon Jun 13 12:46:13 2011 solvik blum
** Last update Wed Jun 29 16:27:04 2011 solvik blum
*/

#include <stdlib.h>
#include <string.h>

#include "player.h"
#include "voir.h"
#include "map.h"
#include "server_zappy.h"

static char     *concat(char *msg, char *concat)
{
  char          *new;
  int           len;

  len = (msg != NULL) ? strlen(msg) : 0;
  new = realloc(msg, len + strlen(concat) + 1);
  strcat(new, concat);
  return (new);
}

static void	check_case(int pos, char **ret)
{
  t_box		*map;
  int		i;
  int		j;

  i = 0;
  j = 0;
  map = get_map();
  for (i = 0; i < get_list_len(map[i].players); i++)
    *ret = concat(*ret, " joueur");
  for (i = 0; i < map[i].food; i++)
    *ret = concat(*ret, " nourriture");
  for (i = 0; i < get_list_len(map[i].stones); i++)
    for (j = 0; j < sizeof(gl_ressource_name) / sizeof(t_enum_to_ressource); j++)
      *ret = concat(*ret, gl_ressource_name[j].str);
}


static void	zappy_voir_north(int pos, int step, char **ret)
{
  int		angle_y;
  int		angle_x;
  int		to_check;
  int		i;

  angle_y = 0;
  angle_x = 0;
  i = pos;
  while (step != 0)
    {
      check_case(i, ret);
      while (angle_x != 0)
	{
	  to_check = i - angle_x;
	  if (to_check / get_map_width() != (pos / get_map_width()))
	    to_check += get_map_width();
	  check_case(to_check, ret);
	  to_check = i + angle_x;
	  if (to_check / get_map_width() != (pos / get_map_width()))
	    to_check -= get_map_width();
	  check_case(to_check, ret);
	  angle_x--;
	}
      i -= get_map_width();
      if (i < 0)
	i += get_map_max();
      step--;
      angle_y++;
      angle_x = angle_y;
    }
}

static void	zappy_voir_south(int pos, int step, char **ret)
{
  int		angle_y;
  int		angle_x;
  int		to_check;
  int		i;

  angle_x = 0;
  angle_y = 0;
  i = pos;
  while (step != 0)
    {
      check_case(i, ret);
      while (angle_x != 0)
	{
	  to_check = i - angle_x;
	  if (to_check / get_map_width() != (pos / get_map_width()))
	    to_check += get_map_width();
	  check_case(to_check, ret);
	  to_check = i + angle_x;
	  if (to_check / get_map_width() != (pos / get_map_width()))
	    to_check -= get_map_width();
	  check_case(to_check, ret);
	  angle_x--;
	}
      i += get_map_width();
      if (i > get_map_max())
	i -= get_map_max();
      step--;
      angle_y++;
      angle_x = angle_y;
    }
}

static void	zappy_voir_west(int pos, int step, char **ret)
{
  int		to_check;
  int		angle_y;
  int		angle_x;
  int		i;

  angle_x = 0;
  angle_y = 0;
  i = pos;
  while (step != 0)
    {
      check_case(i, ret);
      while (angle_x != 0)
	{
	  to_check = i - (get_map_width() * angle_x);
	  if (to_check < 0)
	    to_check += get_map_max();
	  check_case(to_check, ret);
	  to_check = i + (get_map_width() * angle_x);
	  if (to_check > get_map_max())
	    to_check -= get_map_max();
	  check_case(to_check, ret);
	  angle_x--;
	}
      i--;
      if (i / get_map_width() != (pos / get_map_width()))
	i += get_map_width();
      step--;
      angle_y++;
      angle_x = angle_y;
    }
}

static void	zappy_voir_east(int pos, int step, char **ret)
{
  int		to_check;
  int		angle_y;
  int		angle_x;
  int		i;

  angle_x = 0;
  angle_y = 0;
  i = pos;
  while (step != 0)
    {
      check_case(i, ret);
      while (angle_x != 0)
	{
	  to_check = i - (get_map_width() * angle_x);
	  if (to_check < 0)
	    to_check += get_map_max();
	  check_case(to_check, ret);
	  to_check = i + (get_map_width() * angle_x);
	  if (to_check > get_map_max())
	    to_check -= get_map_max();
	  check_case(to_check, ret);
	  angle_x--;
	}
      i++;
      if (i / get_map_width() != (pos / get_map_width()))
	i -= get_map_width();
      step--;
      angle_y++;
      angle_x = angle_y;
    }
}

static const t_zappy_voir	voir_func[4] =
  {
    {NORTH, zappy_voir_north},
    {SOUTH, zappy_voir_south},
    {WEST, zappy_voir_west},
    {EAST, zappy_voir_east},
  };

int		zappy_voir(t_fds *client, char *cmd)
{
  t_box		*map;
  int		pos;
  int		step;
  int		size;
  int		i;
  char		*ret;

  (void)cmd;
  pos  = player_data->x + get_map_width() * player_data->y;
  step = player_data->level;
  if ((ret = strdup("{")) == NULL)
    return (0);
  size = sizeof(voir_func) / sizeof(t_zappy_voir);
  i = 0;
  while (i < size)
    {
      if (player_data->direction == voir_func[i].dir)
	voir_func[i].f(pos, step, &ret);
    }
  if ((ret = concat(ret, "}")) == NULL)
    return (0);
  sends(client, ret);
  return (1);
}

