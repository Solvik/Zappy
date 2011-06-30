/*
** del_node_at.c for  in /Users/Lifely/Developer/project/Zappy/lib/List
** 
** Made by Julien Di Marco
** Login   <Lifely@epitech.net>
** 
** Started on  Thu Jun 30 05:39:03 2011 Julien Di Marco
** Last update Thu Jun 30 05:39:03 2011 Julien Di Marco
*/

#include	<stdlib.h>
#include	"list.h"

void *		del_node_at(t_list ** list, unsigned int pos)
{
  return (del_node(list, get_node_at(*list, pos)));
}
