/*
** main.c for Zappy in ./server_zappy/src
** 
** Made by di-mar_j
** Login   <di-mar_j@epitech.net>
** 
** Started on  Thu Jun 23 22:12:26 2011 di-mar_j
** Last update Sun Jul 10 23:15:49 2011 di-mar_j
*/

#include	<stdlib.h>

#include	"server_zappy.h"

int		main(int argc, char *argv[])
{
  return (server_zappy(argc, argv) ? EXIT_SUCCESS : EXIT_FAILURE);
}
