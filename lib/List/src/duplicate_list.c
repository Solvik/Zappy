/*
** duplicate_list.c for  in /Users/Lifely/Developer/project/Zappy/lib/List
** 
** Made by Julien Di Marco
** Login   <Lifely@epitech.net>
** 
** Started on  Thu Jun 30 05:40:26 2011 Julien Di Marco
** Last update Thu Jun 30 05:40:26 2011 Julien Di Marco
*/

#include	<stdlib.h>
#include	"list.h"

t_list *	duplicate_list(t_list * list)
{
  return (duplicate_list_elem(list, NULL));
}
