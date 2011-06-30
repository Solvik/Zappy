/*
** insert_data_at.c for  in /Users/Lifely/Developer/project/Zappy/lib/List
** 
** Made by Julien Di Marco
** Login   <Lifely@epitech.net>
** 
** Started on  Thu Jun 30 05:35:52 2011 Julien Di Marco
** Last update Thu Jun 30 05:35:52 2011 Julien Di Marco
*/

#include	"list.h"

bool		insert_data_at(t_list * list, unsigned int pos, void * data)
{
  t_node *	node;

  if (!(node = get_node_at(list, pos)))
    return (false);
  return (insert_data_before(list, node, data));
}
