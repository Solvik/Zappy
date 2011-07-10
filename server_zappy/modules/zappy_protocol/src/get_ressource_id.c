/*
** get_ressource_id.c for Zappy in ./server_zappy/modules/zappy_protocol/src
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
