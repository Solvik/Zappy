/*
** new_node.c for Zappy in ./lib/List/src
** 
** Made by di-mar_j
** Login   <di-mar_j@epitech.net>
** 
** Started on  Thu Jun 23 22:12:26 2011 di-mar_j
** Last update Sun Jul 10 23:15:49 2011 di-mar_j
*/

#include	<stdlib.h>
#include	"list.h"

t_node *	new_node(void * data)
{
  t_node *	new_node;

  if (!(new_node = malloc(sizeof(*new_node))))
    return (NULL);
  new_node->data = data;
  new_node->next = NULL;
  new_node->prev = NULL;
  return (new_node);
}
