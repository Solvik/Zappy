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

static bool	match_box_player(void *data, void *arg)
{
  return ((int)((t_player *)data)->x == ((int *)arg)[0] &&
	  (int)((t_player *)data)->y == ((int *)arg)[1]);
}

void		draw_text(t_visu *visu, char *text, int coor[2]);

void		write_stone(t_visu *v, int amount, int *coor)
{
  char		*text;

  asprintf(&text, "%d", amount);
  draw_text(v, text, coor);
  if (text)
    free(text);
}

void		write_player(t_visu *v, t_player *p)
{
  char		*text;
  int		coor[2];

  coor[1] = 0;
  coor[0] = 700;
  asprintf(&text, "Team : %s Level : %u Life : %u ID : %u", p->team->name, p->level,
	   p->life, p->id);
  draw_text(v, text, coor);
  if (text)
    free(text);
}

void		get_info(int x, int y, t_visu *v)
{
  t_box		*box;
  t_player	*p;
  int		pos[2];
  int		coor[2];

  pos[0] = x;
  pos[1] = y;
  if (!(box = get_data_as_arg(v->map, match_box, pos)))
    return ;
  coor[1] = 0;
  coor[0] = 55;
  write_stone(v, box->linemate, coor);
  coor[0] = 165;
  write_stone(v, box->deraumere, coor);
  coor[0] = 235;
  write_stone(v, box->sibur, coor);
  coor[0] = 360;
  write_stone(v, box->mendiane, coor);
  coor[0] = 440;
  write_stone(v, box->phiras, coor);
  coor[0] = 560;
  write_stone(v, box->thystame, coor);
  coor[0] = 630;
  write_stone(v, box->food, coor);
  if (!(p = get_data_as_arg(v->player, match_box_player, pos)))
    return;
  write_player(v, p);
}
