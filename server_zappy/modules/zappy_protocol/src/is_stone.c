/*
** is_stone.c for  in /home/solvik/tek2/proj/Zappy/server_zappy/modules/zappy_protocol/src
**
** Made by solvik blum
** Login   <blum_s@epitech.net>
**
** Started on  Sun Jul  3 16:23:20 2011 solvik blum
** Last update Sun Jul  3 17:19:44 2011 solvik blum
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

