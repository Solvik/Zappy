/*
** get_ressource_id.c for  in /home/solvik/tek2/proj/Zappy/server_zappy/modules/zappy_protocol/src
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

uint		get_ressource_id(char *str)
{
  uint		i;

  i = 0;
  if (!strcmp(str, "nourriture"))
    return (0);
  while (i < (uint)size_stone)
    {
      if (!strcasecmp(str, &(gl_ressource_name[i].str[1])))
	return (i + 1);
      i++;
    }
  return (0);
}
