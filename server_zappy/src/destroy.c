/*
** destroy.c for  in /Users/Lifely/Developer/project/Zappy/server_zappy
**
** Made by Julien Di Marco
** Login   <Lifely@epitech.net>
**
** Started on  Thu Jun 30 05:06:03 2011 Julien Di Marco
** Last update Sat Jul  9 22:28:20 2011 guillaume gelin
*/

#include	<unistd.h>
#include	<stdlib.h>
#include	<stdio.h>
#include	"tserver.h"

static void	destroy_fds(t_fds *pool)
{
  while (pool)
    {
      net_close(pool);
      pool = pool->next;
    }
}

static void	destroy_map(t_box * map)
{
  size_t	i;

  if (!map)
    return ;
  i = 0;
  while (i < get_map_max())
    {
      destroy_list(&map[i].stones, free);
      destroy_list(&map[i].players, NULL);
      destroy_list(&map[i].eggs, free);
      ++i;
    }
  free(map);
}

static void	destroy_team(void * team)
{
  free(((t_team *)team)->name);
  destroy_list(&((t_team *)team)->players, NULL);
  destroy_list(&((t_team *)team)->egg_list, NULL);
  free(team);
}

void		destroy(void)
{
  t_list	*teams;
  t_list	*eggs;

  teams = get_teams();
  destroy_list(&teams, destroy_team);
  eggs = get_eggs();
  destroy_list(&eggs, NULL);
  destroy_map(get_map());
  destroy_fds(get_fds());
}
