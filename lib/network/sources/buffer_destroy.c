/*
** buffer_destroy.c for  in /Users/Lifely/Developer/project/Zappy/lib/network/sources
** 
** Made by Julien Di Marco
** Login   <Lifely@epitech.net>
** 
** Started on  Sun Jul  3 15:01:32 2011 Julien Di Marco
** Last update Sun Jul  3 15:01:32 2011 Julien Di Marco
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
