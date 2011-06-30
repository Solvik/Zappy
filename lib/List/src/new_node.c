/*
** new_node.c for  in /Users/Lifely/Developer/project/Zappy/lib/List
** 
** Made by Julien Di Marco
** Login   <Lifely@epitech.net>
** 
** Started on  Thu Jun 30 05:35:21 2011 Julien Di Marco
** Last update Thu Jun 30 05:35:21 2011 Julien Di Marco
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
