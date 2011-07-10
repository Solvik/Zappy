/*
** err_print_error.c for Zappy in ./common/src
** 
** Made by di-mar_j
** Login   <di-mar_j@epitech.net>
** 
** Started on  Thu Jun 23 22:12:26 2011 di-mar_j
** Last update Sun Jul 10 23:15:49 2011 di-mar_j
*/

#include	<stdarg.h>
#include	<stdio.h>
#include	<stdbool.h>

bool		print_error(char *msg)
{
  fprintf(stderr, "Error: %s\n", msg);
  return (false);
}

bool		print_perror(char *cmd)
{
  perror(cmd);
  return (false);
}

bool		syntax_print_error(char const *format, ...)
{
  va_list arguments;

  va_start(arguments, format);
  fprintf(stderr, "Error: ");
  vfprintf(stderr, format, arguments);
  va_end(arguments);
  fprintf(stderr, "\n");
  return (false);
}
