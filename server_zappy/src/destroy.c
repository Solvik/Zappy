/*
** destroy.c for  in /Users/Lifely/Developer/project/Zappy/server_zappy
** 
** Made by Julien Di Marco
** Login   <Lifely@epitech.net>
** 
** Started on  Thu Jun 30 05:06:03 2011 Julien Di Marco
** Last update Thu Jun 30 05:06:03 2011 Julien Di Marco
*/

#include	<stdlib.h>
#include	"tserver.h"
#include	"tserver.h"

void		destroy(void)
{
  free(get_map());
}
