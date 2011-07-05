/*
** egg.h for  in /home/solvik/tek2/proj/Zappy/server_zappy
**
** Made by solvik blum
** Login   <blum_s@epitech.net>
**
** Started on  Sun Jul  3 20:32:25 2011 solvik blum
** Last update Tue Jul  5 18:05:39 2011 solvik blum
*/

#ifndef			EGG_H_
# define		EGG_H_

#  include		"ztypes.h"
#  include		"team.h"

enum			e_egg_state
  {
    GROWING,
    HATCHED
  };

typedef struct		s_egg
{
  uint			x;
  uint			y;
  enum e_egg_state	status;
  t_team		*team;
}			t_egg;

bool			egg_eclosion(void *);

#endif			/* !EGG_H_ */
