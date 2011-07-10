/*
** flood_manager.c for Zappy in ./server_zappy/src
** 
** Made by di-mar_j
** Login   <di-mar_j@epitech.net>
** 
** Started on  Thu Jun 23 22:12:26 2011 di-mar_j
** Last update Sun Jul 10 23:15:49 2011 di-mar_j
*/

#include	<unistd.h>
#include	<stdlib.h>
#include	<string.h>
#include	<stdio.h>

#include	"client.h"
#include	"net.h"

char		*flood_check(fds pool, char *s)
{
  t_antiflood	*flood;
  t_client	*info;

  if (!pool || !(info = pool->trick) ||
      !(flood = &info->flood) ||
      !(flood->array))
    return (NULL);
  if (flood->size <= 0 && info->command)
    free(info->command);
  if (flood->size <= 0)
    return ((info->command = s));
  if (flood->write == flood->read)
    memset(&flood->read, 0, sizeof(flood->read) * 2);
  if (s && (flood->write - flood->read) < flood->size)
    flood->array[(flood->write++) % flood->size] = s;
  else if (s)
    {
      free(s);
      buffer_destroy(&pool->read);
    }
  if ((flood->write - flood->read) > 0)
    return (flood->array[(flood->read % flood->size)]);
  return (NULL);
}

bool		flood_read(fds pool)
{
  t_antiflood	*flood;
  t_client	*info;

  if (!pool || !(info = pool->trick) ||
      !(flood = &info->flood) ||
      !(flood->array))
    return (false);
  if (flood->size <= 0 && info->command)
    {
      free(info->command);
      info->command = NULL;
      return (true);
    }
  if (!((flood->write - flood->read) > 0))
    return (false);
  free(flood->array[(flood->read % flood->size)]);
  flood->array[((flood->read++) % flood->size)] = NULL;
  if (flood->write == flood->read && flood->write != 0)
    memset(&flood->read, 0, sizeof(flood->read) * 2);
  return (true);
}

bool		flood_destroy(t_client *c)
{
  t_antiflood	*flood;
  int		i;

  i = -1;
  if (!c || !(flood = &c->flood))
    return (false);
  if (c->command)
    free(c->command);
  while (++i < flood->size)
      if (flood->array[i])
	free(flood->array[i]);
  free(flood->array);
  return (true);
}
