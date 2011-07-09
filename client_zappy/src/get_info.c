/*
** get_info.c for  in /Users/sebastienblot/git/Zappy/client_zappy
** 
** Made by Sebastien Blot
** Login   <sebastienblot@epitech.net>
** 
** Started on  Sat Jul  9 01:35:21 2011 Sebastien Blot
** Last update Sat Jul  9 01:37:28 2011 Sebastien Blot
*/

#include	"client_zappy.h"

static bool	match_box(void *data, void *arg)
{
  return (((t_box *)data)->x == ((int *)arg)[0] &&
	  ((t_box *)data)->y == ((int *)arg)[1]);
}

void		draw_text(t_visu *visu, char *text, int coor[2]);

char		*itoadup(int input, int radix);

void		get_info(int x, int y, t_visu *v)
{
  t_box		*box;
  int		pos[2];
  int		coor[2];

  pos[0] = x;
  pos[1] = y;
  box = get_data_as_arg(v->map, match_box, pos);
  coor[1] = 0;
  coor[0] = 50;
  draw_text(v, itoadup(box->linemate, 10), coor);
  coor[0] = 150;
  draw_text(v, itoadup(box->deraumere, 10), coor);
  coor[0] = 250;
  draw_text(v, itoadup(box->mendiane, 10), coor);
  coor[0] = 350;
  draw_text(v, itoadup(box->phiras, 10), coor);
  coor[0] = 450;
  draw_text(v, itoadup(box->thystame, 10), coor);
  coor[0] = 550;
  draw_text(v, itoadup(box->food, 10), coor);
}
