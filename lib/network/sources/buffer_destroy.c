/*
** buffer_destroy.c for Zappy in ./lib/network/sources
** 
** Made by di-mar_j
** Login   <di-mar_j@epitech.net>
** 
** Started on  Thu Jun 23 22:12:26 2011 di-mar_j
** Last update Sun Jul 10 23:15:49 2011 di-mar_j
*/

#include	<unistd.h>
#include	<stdlib.h>

#define		NETPRIVATE
#include	"network.h"
#include	"buffer.h"

void            *buffer_destroy(buffer *l)
{
  if ((*l))
    {
      buffer_destroy(&((*l)->next));
      if ((*l)->plus)
        free((*l)->plus);
      free((*l));
      *l = NULL;
    }
  return (NULL);
}
