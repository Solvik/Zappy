/*
** test.c for  in /home/di-mar_j/git/Zappy/server_zappy/src
** 
** Made by julien di-marco
** Login   <di-mar_j@epitech.net>
** 
** Started on  Wed Jun 22 17:42:22 2011 julien di-marco
** Last update Wed Jun 22 17:42:22 2011 julien di-marco
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
  int		i;

  while (1)
    {
      pool(pooling);
      tmp = *pooling;
      while (tmp)
      	{
      	  if (tmp->type != SERV && (s = getcmd(tmp)))
      	    {
	      i = -1;
	      printf("Read: [%s]: delimitor: ", s);
	      while (tmp->delim[++i])
	      	printf("[%d]%s", tmp->delim[i], (tmp->delim[i + 1] ? " " : " \n"));
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
      sends(pooling, "Hello1");
      sends(pooling, "Hellooooo2");
      sends(pooling, "Hellooooo3");
      sends(pooling, "Hellooooo4");
      sends(pooling, "Hellooooo5");
      sends(pooling, "Hellooooo6");
      sends(pooling, "Hellooooo7");
      sends(pooling, "Hellooooo8");
      sends(pooling, "Hellooooo9");
      sends(pooling, "Hellooooo10");
      sends(pooling, "Hellooooo11");
      sends(pooling, "Hellooooo12");
      sends(pooling, "Hellooooo13");
      sends(pooling, "Hellooooo14");
      sends(pooling, "Hellooooo15");
      sends(pooling, "Hellooooo17");
      sends(pooling, "Hellooooo18");
      sendneof(pooling, "Hellooooo\n19");
      sendneof(pooling, "Hellooooo\n20");
      sendneof(pooling, "Hellooooo\n21");
      sendneof(pooling, "Hellooooo\n22");
      sendneof(pooling, "Hellooooo\n23");
      sendneof(pooling, "Hellooooo\n24");
      sendneof(pooling, "Hellooooo\n25");
      sendneof(pooling, "Hellooooo\n26");
      sends(pooling, "Hellooooolol");
      while (1)
	pool(&pooling);
    }
  else
    {
      if (add_socket(&pooling, 4242, 10) == -1)
	fprintf(stderr, "Error cannot bind on port 4242\n");
      test(&pooling);
    }
  return (0);
}
