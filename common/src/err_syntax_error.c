/*
** err_syntax_error.c for  in /Users/Lifely/Developer/project/Zappy/common
** 
** Made by Julien Di Marco
** Login   <Lifely@epitech.net>
** 
** Started on  Thu Jun 30 05:30:22 2011 Julien Di Marco
** Last update Thu Jun 30 05:30:22 2011 Julien Di Marco
*/

#include	<stdio.h>
#include	"error.h"

bool		syntax_error(char * filename, int line)
{
  char		error[1024];

  snprintf(error, 1023, "File: %s, syntax error line %d",
	   filename, line);
  return (print_error(error));
}

