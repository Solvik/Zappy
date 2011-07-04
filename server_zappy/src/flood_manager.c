/*
** flood_manager.c for  in /home/di-mar_j/git/Zappy/server_zappy
** 
** Made by julien di-marco
** Login   <di-mar_j@epitech.net>
** 
** Started on  Tue Jun 28 20:06:22 2011 julien di-marco
** Last update Tue Jun 28 20:06:22 2011 julien di-marco
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
   else
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
