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

bool		match_box(void *data, void *arg)
{
  return (((t_box *)data)->x == ((int *)arg)[0] &&
	  ((t_box *)data)->y == ((int *)arg)[1]);
}

static bool	match_box_player(void *data, void *arg)
{
  return ((int)((t_player *)data)->x == ((int *)arg)[0] &&
	  (int)((t_player *)data)->y == ((int *)arg)[1]);
}

void		write_stone(t_visu *v, int amount, int x, int y)
{
  char		*text;
  int		coor[2];

  coor[0] = x;
  coor[1] = y;
  asprintf(&text, "%d", amount);
  draw_text(v, text, coor);
  if (text)
    free(text);
}

void		write_player(t_visu *v, t_player *p)
{
  char		*text;
  int		coor[2];

  coor[0] = 700;
  coor[1] = 0;
  asprintf(&text, "Team : %s Level : %u Life : %u ID : %u", p->team->name,
	   p->level, p->life, p->id);
  draw_text(v, text, coor);
  if (text)
    free(text);
}

void		get_info(int x, int y, t_visu *v)
{
  t_box		*box;
  t_player	*p;
  int		pos[2];

  pos[0] = x;
  pos[1] = y;
  if (!(box = get_data_as_arg(v->map, match_box, pos)))
    return ;
  write_stone(v, box->linemate, 55, 0);
  write_stone(v, box->deraumere, 165, 0);
  write_stone(v, box->sibur, 235, 0);
  write_stone(v, box->mendiane, 360, 0);
  write_stone(v, box->phiras, 440, 0);
  write_stone(v, box->thystame, 560, 0);
  write_stone(v, box->food, 630, 0);
  if (!(p = get_data_as_arg(v->player, match_box_player, pos)))
    return;
  write_player(v, p);
}
