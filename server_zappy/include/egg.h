/*
** egg.h for Zappy in ./server_zappy/include
** 
** Made by di-mar_j
** Login   <di-mar_j@epitech.net>
** 
** Started on  Thu Jun 23 22:12:26 2011 di-mar_j
** Last update Sun Jul 10 23:15:49 2011 di-mar_j
*/

#ifndef			EGG_H_
# define		EGG_H_

#  include		"ztypes.h"
#  include		"player.h"
#  include		"team.h"

enum			e_egg_state
  {
    GROWING,
    HATCHED
  };

#if !defined(_PLAYER_H_)
typedef struct s_player	t_player;
typedef struct s_egg	t_egg;
#endif

struct		s_egg
{
  uint			id;
  uint			idf;
  uint			x;
  uint			y;
  enum e_egg_state	status;

  t_player		*father;
  t_player		*himself;
  t_team	       	*team;
};

bool			egg_eclosion(void *);

# define		_EGG_H_
#endif			/* !EGG_H_ */
