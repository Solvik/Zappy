/*
** server_zappy/main.c for  in /Users/Lifely/Developer/project/Zappy/server_zappy
** 
** Made by Julien Di Marco
** Login   <Lifely@epitech.net>
** 
** Started on  Thu Jun 30 05:04:41 2011 Julien Di Marco
** Last update Thu Jun 30 05:04:41 2011 Julien Di Marco
*/

#include	<stdlib.h>
#include	"server_zappy.h"

int		main(int argc, char *argv[])
{
  return (server_zappy(argc, argv) ? EXIT_SUCCESS : EXIT_FAILURE);
}
