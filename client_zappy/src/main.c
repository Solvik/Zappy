/*
** main.c for Zappy in ./client_zappy/src
** 
** Made by di-mar_j
** Login   <di-mar_j@epitech.net>
** 
** Started on  Thu Jun 23 22:12:26 2011 di-mar_j
** Last update Sun Jul 10 23:15:49 2011 di-mar_j
*/

#include	<stdlib.h>
#include	"client_zappy.h"

int		main(int ac, char *av[])
{
  return (client_zappy(ac, av) ? EXIT_SUCCESS : EXIT_FAILURE);
}
