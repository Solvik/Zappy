/*
** client_zappy.h for  in /Users/Lifely/Developer/project/Zappy/client_zappy
**
** Made by Julien Di Marco
** Login   <Lifely@epitech.net>
**
** Started on  Thu Jun 30 05:33:40 2011 Julien Di Marco
** Last update Wed Jul  6 01:15:47 2011 solvik blum
*/

#ifndef		CLIENT_ZAPPY_H_
# define	CLIENT_ZAPPY_H_

#  include	<stdbool.h>
#  include	"ztypes.h"
#  include	"list.h"
#  include	"network.h"
#  include	"player.h"

#  include	<SDL/SDL.h>

bool		client_zappy(int, char *[]);

typedef struct	s_cmd
{
  int		argc;
  char		**argv;
}		t_cmd;

typedef struct	s_sprite
{
  char		*grass;
}		t_sprite;

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

typedef struct	s_teams
{
  char		*name;
  int		player_id;
}		t_teams;

typedef struct	s_visualiseur
{
  SDL_Surface	*screen;
  t_sprite	*sprite;
  t_list	*map; // t_box
  t_list	*player; // t_player
  t_list	*teams; // t_teams
  int		width;
  int		height;
  int		time;
}		t_visualiseur;

typedef t_visualiseur t_visu;

t_cmd		*parse_cmd(char *);
int		gere_cmd(t_fds *, t_cmd *, t_visu *);



#endif		/* !CLIENT_ZAPPY_H_ */
