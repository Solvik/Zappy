/*
** refresh.c for  in /home/seb/git/Zappy/client_zappy
**
** Made by seb
** Login   <seb@epitech.net>
**
** Started on  Sun Jul 10 09:26:40 2011 seb
** Last update Sun Jul 10 09:26:40 2011 seb
*/

#include	"client_zappy.h"

void		refresh_screen(t_visu *v)
{
  draw_map(v);
  foreach_arg_list(v->player, draw_player, v);
}
