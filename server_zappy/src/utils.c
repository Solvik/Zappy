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
#include	"player.h"

typedef enum	translation_
  {
    VERTICAL,
    HORIZONTAL,
    NONE
  }		e_translation;

typedef struct voir_algo
{
  e_direction	d;
  e_translation	t;
}		t_voir_algo;

static t_voir_algo	algo[] =
  {
    {NORTH, NONE},
    {EAST, VERTICAL},
    {NORTH, HORIZONTAL},
    {EAST, NONE}
  };

#define EDIRSIZE sizeof(algo) / sizeof(t_voir_algo)

void		voir_iter(e_direction d, int l)
{
  t_voir_algo	*dir;
  int		x;
  int		y;
  int		s;
  int		j;

  if (d > EDIRSIZE)
    return ;
  dir = &algo[d];
  s = (2 * 1) * dir->d;
  printf("s: %d\n", s);
  j = -1;
  while (++j < (3 + (2 * (l - 1))))
    {
      x = ( (5 + (s % (3 + (2 * (l - 1))))) - l );
      y = ( (5 + (s / (3 + (2 * (l - 1))))) - l );
      x = (dir->t == VERTICAL) ? 5 - (x - 5) : (dir->t == HORIZONTAL) ? 5 - (x - 5) : x;
      y = (dir->t == VERTICAL) ? 5 - (y - 5) : (dir->t == HORIZONTAL) ? 5 - (y - 5) : y;
      printf("{ x = %d", x);
      printf(", y = %d}\n", y);
      s += (dir->d == NORTH) ? 1 : (3 + (2 * (l - 1)));
    }
}

int		main(int ac, char **av)
{
  if (ac >= 3)
    voir_iter(atoi(av[1]), atoi(av[2]));
  return (0);
}
