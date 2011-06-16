
/*
** main.c for  in /home/di-mar_j//svn/irc/branches/network
** 
** Made by julien di-marco
** Login   <di-mar_j@epitech.net>
** 
** Started on  Tue Apr 19 16:46:51 2011 julien di-marco
** Last update Tue Apr 19 16:46:51 2011 julien di-marco
*/

#include	<unistd.h>
#include	<stdlib.h>
#include	<string.h>
#include	<stdio.h>
#include	<errno.h>

#include	"network.h"

static int	test(fds *pooling)
{
  char		*s;
  fds		tmp;

  while (1)
    {
      pool(pooling);
      tmp = *pooling;
      while (tmp)
      	{
      	  if (tmp->type != SERV && (s = getcmd(tmp)))
      	    {
	      sendneof(tmp, "old [");
	      sendneof(tmp, (*(char**)tmp) ? (*(char**)tmp) : "NULL");
	      sendneof(tmp, "] and new [");
	      sendneof(tmp, s);
	      sends(tmp, "].");

	      free(*(void**)tmp);
	      *((char**)tmp) = s;
      	    }
      	  tmp = tmp->next;
      	}
    }
  return (0);
}

int		main(int ac, char **av)
{
  fds		pooling;

  (void)av;
  free_data = NULL;
  pooling = NULL;
  printf("Lets Get started\n");
  if (ac > 1)
    {
      if (add_co(&pooling, "localhost", 4242) == -1)
	fprintf(stderr, "Error connecting on %s:%d\n", "localhost", 4242);
    }
  else
    {
      if (add_socket(&pooling, 4242, 10) == -1)
	fprintf(stderr, "Error cannot bind on port 4242\n");
    }
  test(&pooling);
  return (0);
}
