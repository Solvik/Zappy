/*
** is_stone.c for Zappy in ./server_zappy/modules/zappy_protocol/src
** 
** Made by di-mar_j
** Login   <di-mar_j@epitech.net>
** 
** Started on  Thu Jun 23 22:12:26 2011 di-mar_j
** Last update Sun Jul 10 23:15:49 2011 di-mar_j
*/

#include	<string.h>

#include	"napi.h"

#include	"voir.h"
#include	"zappy_protocol.h"

e_stone		is_stone(char *str)
{
  int		i;

  i = 0;
  while (i < size_stone)
    {
      if (!strcasecmp(str, &(gl_ressource_name[i].str[1])))
	return (gl_ressource_name[i].stone);
      i++;
    }
  return (NONE);
}

void		stone(void *elem, void *arg)
{
  t_stone	*stone;
  fds		c;
  int		i;

  if (!(stone = (t_stone*)elem) || !(c = (fds)arg))
    return ;
  i = -1;
  while (++i < (int)stone->nb)
    if ((int)stone->type < size_stone)
      sendneof(c, gl_ressource_name[stone->type].str);
}

