/*
** dump_list.c for  in /Users/Lifely/Developer/project/Zappy/lib/List
** 
** Made by Julien Di Marco
** Login   <Lifely@epitech.net>
** 
** Started on  Thu Jun 30 05:38:55 2011 Julien Di Marco
** Last update Thu Jun 30 05:38:55 2011 Julien Di Marco
*/

#include	"list.h"

void		dump_list(t_list * list, void (*displayer)(void *))
{
  foreach_list(list, displayer);
}

