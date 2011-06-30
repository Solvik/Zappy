/*
** put_in_list.c for  in /Users/Lifely/Developer/project/Zappy/lib/List
** 
** Made by Julien Di Marco
** Login   <Lifely@epitech.net>
** 
** Started on  Thu Jun 30 05:35:04 2011 Julien Di Marco
** Last update Thu Jun 30 05:35:04 2011 Julien Di Marco
*/

#include	<strings.h>
#include	<stdlib.h>
#include	"list.h"

static bool	list_init(t_list ** list, void * data)
{
  t_node *	new;

  if (!(*list = malloc(sizeof(**list)))
      || !(new = new_node(data)))
    return (false);
  bzero(*list, sizeof(**list));
  (*list)->len = 1;
  (*list)->begin = new;
  (*list)->end = new;
  return (true);
}

bool		put_in_list(t_list ** list, void * data)
{
  t_node *	new;

  if (!list)
    return (false);
  if (!*list)
    return (list_init(list, data));
  if (!(new = new_node(data)))
    return (false);
  (*list)->end->next = new;
  new->prev = (*list)->end;
  (*list)->end = new;
  ++((*list)->len);
  return (true);
 }
