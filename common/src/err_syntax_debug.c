/*
** err_syntax_error.c for  in /Users/Lifely/Developer/project/Zappy/common
** 
** Made by Julien Di Marco
** Login   <Lifely@epitech.net>
** 
** Started on  Thu Jun 30 05:30:22 2011 Julien Di Marco
** Last update Thu Jun 30 05:30:22 2011 Julien Di Marco
*/

#include	<stdarg.h>
#include	<stdio.h>
#include	"error.h"

bool		print_debug(char const *format, ...)
{
#if !defined(NDEGUB)
  va_list arguments;

  va_start(arguments, format);
  fprintf(stderr, "Debug: ");
  vfprintf(stderr, format, arguments);
  va_end(arguments);
  fprintf(stderr, "\n");
  return (true);
#else
  return (false);
#endif
}

bool		print_debug_(bool a, char const *format, ...)
{
#if !defined(NDEGUB)
  va_list arguments;

  va_start(arguments, format);
  if (a)
    fprintf(stderr, "Debug: ");
  vfprintf(stderr, format, arguments);
  va_end(arguments);
  return (true);
#else
  return (false);
#endif
}

