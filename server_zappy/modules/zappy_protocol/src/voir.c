/*
** voir.c for  in /home/solvik/tek2/proj/Zappy/server_zappy/src
**
** Made by solvik blum
** Login   <blum_s@epitech.net>
**
** Started on  Mon Jun 13 12:46:13 2011 solvik blum
** Last update Tue Jul  5 22:41:06 2011 solvik blum
*/

#include <stdlib.h>
#include <string.h>
#include <stdio.h>

#include "napi.h"

#include "voir.h"

static t_voir_algo	algo[] =
  {
    {NORTH, HORIZONTAL},	/* e_direction NORTH */
    {EAST, VERTICAL},		/* e_direction EAST */
    {NORTH, NORMAL},		/* e_direction SOUTH */
    {EAST, NORMAL}		/* e_direction WEST */
  };

static void	voir_(t_fds *c, int index)
{
  t_box		*map;
  int		i;
  int		j;

  i = 0;
  j = 0;
  if (!c || !(map = get_map()))
    return ;
  while (i < get_list_len(map[index].players))
    {
      sendneof(c, " joueur");
      i += 1;
    }
  i = 0;
  while (i < (int)map[index].food)
    {
      sendneof(c, " nourriture");
      i += 1;
    }
  foreach_arg_list(map[index].stones, stone, c);
}

static void	voir_case(t_fds *c, int x, int y)
{
  int		index;

  if (!c)
    return ;
  x = X(x);
  y = Y(y);
  index = x + get_map_width() * y;
  print_debug_(false, "{x: %d, y: %d, i: %d} ", x, y, index);
  if (index >= 0 && index < (int)(get_map_width() * get_map_height()))
    voir_(c, index);
}

static void	voir_level(t_fds *c, t_player *p, int l)
{
  t_voir_algo	*d;
  int		x;
  int		y;
  int		s;
  int		i;

  i = -1;
  if (!c || !p || l <= -1 || (p->direction >= EDIRSIZE))
    return ;
  d = &algo[p->direction];
  s = (2 * 1) * d->d;
  while (++i < (3 + (2 * (l - 1))))
    {
      x = ((p->x + (s % (3 + (2 * (l - 1))))) - l);
      y = ((p->y + (s / (3 + (2 * (l - 1))))) - l);
      x = (d->t != NORMAL) ? (int)p->x - (x - (int)p->x) : x;
      y = (d->t != NORMAL) ? (int)p->y - (y - (int)p->y) : y;
      voir_case(c, x, y);
      s += (d->d == NORTH) ? 1 : (3 + (2 * (l - 1)));
      if (!(l == (int)p->level && ((i + 1) == (3 + (2 * (l - 1))))))
	sendneof(c, ",");
    }
  print_debug_(false, "\n");
}

static void	voir_algorithm(t_fds *c, t_player *p)
{
  int		i;

  i = 0;
  if (!c || !p)
    return ;
  print_debug("User: d[%d] {x: %d, y: %d}", p->direction, p->x, p->y);
  voir_case(c, p->x, p->y);
  print_debug_(false, "\n");
  sendneof(c, ",");
  while (++i <= (int)p->level)
    voir_level(c, p, i);
}

int		zappy_voir(t_fds *c, char *_)
{
  t_player	*p;
  (void)_;

  if (!c || !(p = *(t_player**)c))
    return (false);
  sendneof(c, "{");
  voir_algorithm(c, p);
  sends(c, "}");
  return (true);
}
