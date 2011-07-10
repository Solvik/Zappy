/*
** voir.c for  in /home/solvik/tek2/proj/Zappy/server_zappy/src
**
** Made by solvik blum
** Login   <blum_s@epitech.net>
**
** Started on  Mon Jun 13 12:46:13 2011 solvik blum
** Last update Sun Jul 10 14:00:14 2011 guillaume gelin
*/

#define		_GNU_SOURCE

#include	<unistd.h>
#include	<stdlib.h>
#include	<string.h>
#include	<stdio.h>

#include	"napi.h"

#include	"zappy_protocol.h"

typedef struct	s_elevation
{
  uint		nb_players;
  uint		linemate;
  uint		deraumere;
  uint		sibur;
  uint		mendiane;
  uint		phiras;
  uint		thystame;
}		t_elevation;

static const t_elevation	elevation[] =
  {
    {1, 1, 0, 0, 0, 0, 0},
    {2, 1, 1, 1, 0, 0, 0},
    {2, 2, 0, 1, 0, 2, 0},
    {4, 1, 1, 2, 0, 1, 0},
    {4, 1, 2, 1, 3, 0, 0},
    {6, 1, 2, 3, 0, 1, 0},
    {6, 2, 2, 2, 2, 2, 1}
  };

#define ELV	elevation[level]

static bool	verif_incantation(t_player *p)
{
  int		level;
  bool		out;
  int		x;
  int		y;

  out = false;
  if (!p || ((level = (p->level - 1)) < 0) ||
      (level >= (int)(sizeof(elevation) / sizeof(t_elevation))))
    return (out);
  x = p->x;
  y = p->y;
  memcpy(&p->x, &p->inca.x, (sizeof(p->x) * 2));
  if ((ELV.linemate == get_box_nbstones(p->x, p->y, LINEMATE)) &&
      (ELV.deraumere == get_box_nbstones(p->x, p->y, DERAUMERE)) &&
      (ELV.sibur == get_box_nbstones(p->x, p->y, SIBUR)) &&
      (ELV.mendiane == get_box_nbstones(p->x, p->y, MENDIANE)) &&
      (ELV.phiras == get_box_nbstones(p->x, p->y, PHIRAS)) &&
      (ELV.thystame == get_box_nbstones(p->x, p->y, THYSTAME)) &&
      ELV.nb_players == (uint)get_list_len(get_box_players_by_level(p->x, p->y,
								    level + 1)))
    out = true;
  p->x = x;
  p->y = y;
  return (out);
}

static int	first_test(fds c)
{
  t_player	*p;

  if (!c || !(p = *(t_player**)c))
    return (false);
  p->inca.x = p->x;
  p->inca.y = p->y;
  sends(c, "elevation en cours");
  scheduler_relative(c, schedule_incantation,
		     (bool(*)(fds, void*))zappy_incantation, NULL);
  scheduler_free(c);
  return (-1);
}

static	void	send_elev(void *e, void *a)
{
  t_player	*p;
  fds		c;
  int		*b;

  if (!(p = (t_player*)e) || !(b = (int*)a))
    return ;
  p->team += 1;
  if ((c = p->client))
    sendf(c, "niveau actuel : %d", *b);
}

static int	second_test(fds c)
{
  t_player	*p;
  t_list	*players;
  int		level;

  players = NULL;
  if (!c || !(p = *(t_player**)c))
    return (false);
  if (!verif_incantation(p) ||
      !(players = get_box_players_by_level(p->inca.x, p->inca.y, p->level)))
    {
      sends(c, "ko");
      return (false);
    }
  level = p->level + 1;
  foreach_arg_list(players, send_elev, &level);
  return (true);
}


int		zappy_incantation(fds c, char *_)
{
  t_generic	data;
  t_player	*p;

  (void)_;
  memset(&data, 0, sizeof(data));
  if (!c || !(p = *(t_player**)c))
    return (false);
  if (!scheduler_active(c))
    return (first_test(c));
  else
    {
      if (second_test(c))
	data.ui3 = 1;
      data.ui1 = p->inca.x;
      data.ui2 = p->inca.y;
      event_relative_dispatch("IncaEnd", &data, 0);
      return (data.ui3);
    }
  return (true);
}
