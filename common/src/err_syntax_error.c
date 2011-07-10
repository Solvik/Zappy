/*
** err_syntax_error.c for Zappy in ./common/src
** 
** Made by di-mar_j
** Login   <di-mar_j@epitech.net>
** 
** Started on  Thu Jun 23 22:12:26 2011 di-mar_j
** Last update Sun Jul 10 23:15:49 2011 di-mar_j
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

