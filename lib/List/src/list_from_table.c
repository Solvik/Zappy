/*
** list_from_table.c for  in /Users/Lifely/Developer/project/Zappy/lib/List
** 
** Made by Julien Di Marco
** Login   <Lifely@epitech.net>
** 
** Started on  Thu Jun 30 05:35:25 2011 Julien Di Marco
** Last update Thu Jun 30 05:35:25 2011 Julien Di Marco
*/

#include	<stdlib.h>
#include	<unistd.h>
#include	"list.h"

t_list *	list_from_table(char ** table)
{
  t_list *	list;
  ssize_t	i;

  list = NULL;
  i = 0;
  while (table && table[i])
    {
      if (!(put_in_list(&list, table[i])))
	return (NULL);
      ++i;
    }
  return (list);
}
