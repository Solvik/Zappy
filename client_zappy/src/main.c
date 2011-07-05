/*
** main.c for  in /Users/Lifely/Developer/project/Zappy/client_zappy
** 
** Made by Julien Di Marco
** Login   <Lifely@epitech.net>
** 
** Started on  Thu Jun 30 05:33:35 2011 Julien Di Marco
** Last update Thu Jun 30 05:33:35 2011 Julien Di Marco
*/

#include	<stdlib.h>
#include	"client_zappy.h"

int		main(int ac, char *av[])
{
  return (client_zappy(ac, av) ? EXIT_SUCCESS : EXIT_FAILURE);
}
