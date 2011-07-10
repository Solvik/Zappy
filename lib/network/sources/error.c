/*
** error.c for Zappy in ./lib/network/sources
** 
** Made by di-mar_j
** Login   <di-mar_j@epitech.net>
** 
** Started on  Thu Jun 23 22:12:26 2011 di-mar_j
** Last update Sun Jul 10 23:15:49 2011 di-mar_j
*/

#include	<unistd.h>
#include	<stdlib.h>
#include	<stdarg.h>
#include	<stdio.h>

#include	"network.h"

void		error(char const *format, ...)
{
  va_list arguments;

  va_start(arguments, format);
#if defined(ERRORMSG)
  fprintf(stderr, "Pool: ");
  vfprintf(stderr, format, arguments);
#endif
  va_end(arguments);
#if defined(ERRORMSG)
  fprintf(stderr, "\n");
#endif
}
