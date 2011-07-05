/*
** client_zappy.h for  in /Users/Lifely/Developer/project/Zappy/client_zappy
**
** Made by Julien Di Marco
** Login   <Lifely@epitech.net>
**
** Started on  Thu Jun 30 05:33:40 2011 Julien Di Marco
** Last update Tue Jul  5 19:07:34 2011 solvik blum
*/

#ifndef		CLIENT_ZAPPY_H_
# define	CLIENT_ZAPPY_H_

#  include	<stdbool.h>
#  include	"ztypes.h"

bool		client_zappy(void);

typedef struct	s_sprite
{
  char		*grass;
}		t_sprite;

typedef struct	s_ressource
{
  char		*name;
  uint		nb;
}		t_ressource;

typedef struct	s_box
{
  int		linemate;
  int		deraumere;
  int		sibur;
  int		mendiane;
  int		phiras;
  int		thystame;
  int		egg;
  int		food;
}		t_box;

typedef struct	s_visualiseur
{
  SDL_Surface	*screen;
  t_sprite	*sprite;
  t_list	*map; // t_box
  t_list	*player; // t_player
}		t_visualiseur;

typedef t_visualiseur t_visu;

#endif		/* !CLIENT_ZAPPY_H_ */
