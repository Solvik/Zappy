/*
** voir.c for  in /home/solvik/tek2/proj/Zappy/server_zappy/src
**
** Made by solvik blum
** Login   <blum_s@epitech.net>
**
** Started on  Mon Jun 13 12:46:13 2011 solvik blum
** Last update Wed Jun 29 17:47:20 2011 solvik blum
*/

#include <stdlib.h>
#include <string.h>

#include "tserver.h"

#include "player.h"
#include "voir.h"
#include "map.h"
#include "server_zappy.h"

void	zappy_voir_east(int pos, int step, char **ret);
void	zappy_voir_west(int pos, int step, char **ret);
void	zappy_voir_south(int pos, int step, char **ret);
void	zappy_voir_north(int pos, int step, char **ret);

void		check_case(int _, char **ret);

static const t_zappy_voir	voir_func[4] =
  {
    {NORTH, zappy_voir_north},
    {SOUTH, zappy_voir_south},
    {WEST, zappy_voir_west},
    {EAST, zappy_voir_east},
  };

int	_voir_ns(char **ret, int i, int x, int pos)
{
  int	check;

  check = 0;
  while (--x != 0)
    {
      if (((check =  (i - x)) / get_map_width()) != (pos / get_map_width()))
	check += get_map_width();
      check_case(check, ret);
      if (((check = (i + x)) / get_map_width()) != (pos / get_map_width()))
	check -= get_map_width();
      check_case(check, ret);
    }
  return (check);
}

int	_voir_ne(char **ret, int i, int x, int _)
{
  int	check;

  (void)_;
  check = 0;
  while (--x != 0)
    {
      if ((check = (i - (get_map_width() * x))) < 0)
	check += get_map_max();
      check_case(check, ret);
      if ((check =  (i + (get_map_width() * x))) > (int)get_map_max())
	check -= get_map_max();
      check_case(check, ret);
    }
  return (check);
}

char     *concat(char *msg, char *concat)
{
  char          *new;
  int           len;

  len = (msg != NULL) ? strlen(msg) : 0;
  new = realloc(msg, (len + strlen(concat) + 1));
  strcat(new, concat);
  return (new);
}

int		zappy_voir(t_fds *client, char *cmd)
{
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

