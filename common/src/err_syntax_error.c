
#include	<stdio.h>
#include	"error.h"

bool		syntax_error(char * filename, int line)
{
  char		error[1024];

  snprintf(error, 1023, "File: %s, syntax error line %d",
	   filename, line);
  return (print_error(error));
}

