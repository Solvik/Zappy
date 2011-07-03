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

#include	"voir.h"

e_stone		is_stone(char *str)
{
  int		i;

  i = 0;
  while (i < size_stone)
    {
      if (!strcmp(str, &(gl_ressource_name[i].str[1])))
	return (gl_ressource_name[i].stone);
      i++;
    }
  return (NONE);
}
