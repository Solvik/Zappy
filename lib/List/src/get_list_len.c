/*
** get_list_len.c for  in /Users/Lifely/Developer/project/Zappy/lib/List
** 
** Made by Julien Di Marco
** Login   <Lifely@epitech.net>
** 
** Started on  Thu Jun 30 05:36:10 2011 Julien Di Marco
** Last update Thu Jun 30 05:36:10 2011 Julien Di Marco
*/

#include	"list.h"

int		get_list_len(t_list * list)
{
  return (list ? list->len : 0);
}
