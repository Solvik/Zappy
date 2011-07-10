/*
** player.h for Zappy in ./server_zappy/include
** 
** Made by di-mar_j
** Login   <di-mar_j@epitech.net>
** 
** Started on  Thu Jun 23 22:12:26 2011 di-mar_j
** Last update Sun Jul 10 23:15:49 2011 di-mar_j
*/

#ifndef		PLAYER_H_
# define	PLAYER_H_

#  include	"ztypes.h"
#  include	"list.h"

# include	"egg.h"
# include	"team.h"
# include	"net.h"

#define		player_data	((t_player *)(client->data))

typedef enum
  {
    NORTH = 0,
    EAST,
    SOUTH,
    WEST
  }		e_direction;

#if !defined(_EGG_H_)
typedef struct s_egg	t_egg;
typedef struct s_player	t_player;
#endif

typedef struct	_case
{
  int	x;
  int	y;
}		t_case;

struct		s_player
{
  uint		id;
  uint		level;
  int		x;
  int		y;
  t_list 	*stones;
  e_direction	direction;

  t_fds		*client;
  t_team	*team;
  t_egg		*egg;
  t_case	inca;

  bool		fork;
  uint		food;
  double	foodt;
  double	foodlt;
};

/*
** See destroy.c
*/

t_player        *player_destroy(t_player *);
t_player	*init_player(t_team *team);

# define	_PLAYER_H_
#endif		/* PLAYER_H_ */
