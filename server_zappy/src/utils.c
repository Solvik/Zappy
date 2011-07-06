/*
** server_zappy/voir.c for  in /Users/Lifely/Developer/project/Zappy/server_zappy/modules/zappy_protocol
** 
** Made by Julien Di Marco
** Login   <Lifely@epitech.net>
** 
** Started on  Wed Jul  6 15:05:49 2011 Julien Di Marco
** Last update Wed Jul  6 15:05:49 2011 Julien Di Marco
*/


/*       1 2 3 4 5 6 7 8 9              0  1 2 3 4 5  6 */
/*       1 2 3 4 5 6 7 8 9              7  0 1 2 3 4  13 */
/*       1 2 3 4 5 6 7 8 9             14  5 0 1 2 9  20 */
/*       1 2 3 4 5 6 7 8 9             21 10 3 . 5 14 27 */
/*       1 2 3 4 . 6 7 8 9             28 15 6 7 8 19 34 */
/*       1 2 3 4 5 6 7 8 9             35 20 1 2 3 24 41 */
/*       1 2 3 4 5 6 7 8 9             42 43 4 5 6 47 48 */
/*       1 2 3 4 5 6 7 8 9 */
/*       1 2 3 4 5 6 7 8 9 */

/* NORTH */
/* -------- */
/* X = ((x + (n % 3)) - 1) - NORTH */
/* X = ((x + (n % (3 + (2 * l)))) - (1 * l)) */
/* X = ((x + ([n ... a] % a)) - b) */
/* a = (3 + (2 * (l - 1))) */
/* b = (1 * l) */
/* n = 0 */
/* ... = n + 1 */
/* -------------- */


/* EST */
/* -------- */
/* X = ((x + (n % 3)) - 1) - NORTH */
/* X = ((x + (n % (3 + (2 * l)))) - (1 * l)) */
/* X = ((x + ([n ... a] % a)) - b) */
/* a = (3 + (2 * (l - 1))) */
/* b = (1 * l) */
/* n = 2 * l */
/* ... = n + (3 + (2 * (l - 1))) */
/* ------- */

/* ((5 + ((0 + (2 * 1)) % (3 + (2 * 1)))) - (2 * 1)) */

#include	<unistd.h>
#include	<stdlib.h>
#include	<stdio.h>

int		main(int ac, char **av)
{
  int		x;
  int		s;
  int		l;
  int		i;
  int		j;

  if (ac < 3)
    return (-1);
  x = atoi(av[1]);
  l = atoi(av[2]);
  s = 0;
  s = (2 * l);
  j = -1;
  while (++j < (3 + (2 * (l - 1))))
    {
      printf("{ x = %d", ( (x + (s % (3 + (2 * (l - 1))))) - l ));
      printf(", y = %d}\n", ( (x + (s / (3 + (2 * (l - 1))))) - l ));
      s += (3 + (2 * (l - 1)));
/*       s += 1; */
    }
  return (0);
}
