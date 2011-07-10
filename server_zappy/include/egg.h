/*
** egg.h for  in /home/solvik/tek2/proj/Zappy/server_zappy
**
** Made by solvik blum
** Login   <blum_s@epitech.net>
**
** Started on  Sun Jul  3 20:32:25 2011 solvik blum
** Last update Fri Jul  8 09:49:13 2011 ramnes
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
  t_team	       	*team;
};

bool			egg_eclosion(void *);

# define		_EGG_H_
#endif			/* !EGG_H_ */
