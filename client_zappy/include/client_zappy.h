/*
** client_zappy.h for Zappy in ./client_zappy/include
** 
** Made by di-mar_j
** Login   <di-mar_j@epitech.net>
** 
** Started on  Thu Jun 23 22:12:26 2011 di-mar_j
** Last update Sun Jul 10 23:15:49 2011 di-mar_j
*/

#ifndef		CLIENT_ZAPPY_H_
# define	CLIENT_ZAPPY_H_

#  include	<stdbool.h>
#  include	<SDL/SDL.h>
#  include	<SDL/SDL_ttf.h>
#  include	"ztypes.h"
#  include	"list.h"
#  include	"network.h"
#  include	"player.h"

#  define	WIDTH		1024
#  define	HEIGHT		768
#  define	SCROLL		2

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
  int		x;
  int		y;
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
  SDL_Surface	*draw;
  SDL_Surface	*info;
  SDL_Rect	camera;
  TTF_Font	*police;
  t_sprite	*sprite;
  t_list	*map; /* t_box */
  t_list	*player; /* t_player */
  t_list	*teams; /* t_team */
  int		width;
  int		height;
  int		time;
  bool		refresh;
}		t_visualiseur;

typedef		t_visualiseur	t_visu;

t_cmd		*parse_cmd(char *);
int		gere_cmd(t_fds *, t_cmd *, t_visu *);
bool		client_zappy(int, char *[]);
void		free_cmd(t_cmd *);
t_player	*get_player_by_id(t_visu *, int );
void		draw_map(t_visu *);
void		draw_player(void *, void *);
void		refresh_screen(t_visu *);
void		draw_info(t_visu *);
void		get_info(int, int, t_visu *);
int		send_bct(t_fds *, t_cmd *);
void		draw_text(t_visu *, char *, int [2]);
void		handle_event(t_fds **, t_visu *);
bool		match_box(void *, void *);
void		draw_stones(t_visu *, int, int);

#endif		/* !CLIENT_ZAPPY_H_ */
