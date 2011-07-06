/*
** init_random.c for  in /Users/Lifely/Developer/project/Zappy/server_zappy
** 
** Made by Julien Di Marco
** Login   <Lifely@epitech.net>
** 
** Started on  Wed Jul  6 12:22:40 2011 Julien Di Marco
** Last update Wed Jul  6 12:22:40 2011 Julien Di Marco
*/

#include	<unistd.h>
#include	<stdlib.h>
#include	<stdio.h>
#include	<time.h>

#include	"zopt.h"
#include	"error.h"
#include	"tserver.h"
#include	"server_zappy.h"

bool		init_random(t_zopt *opt)
{
  if (!opt)
    return (false);
#if defined(_Darwin_)
  if ((int)opt->seed == -1)
    sranddev();
  else
#endif
    srand(opt->seed);
  return (true);
}
