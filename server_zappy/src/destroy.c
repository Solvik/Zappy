/*
** destroy.c for Zappy in ./server_zappy/src
** 
** Made by di-mar_j
** Login   <di-mar_j@epitech.net>
** 
** Started on  Thu Jun 23 22:12:26 2011 di-mar_j
** Last update Sun Jul 10 23:15:49 2011 di-mar_j
*/

#include	<unistd.h>
#include	<stdlib.h>
#include	<stdio.h>
#include	<dlfcn.h>

#include	"exec.h"
#include	"event.h"
#include	"tserver.h"

extern t_server	*gserv;

void		destroy_event(void);
void		destroy_module(void);

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
  destroy_fds(get_fds());
  destroy_list(&teams, destroy_team);
  eggs = get_eggs();
  destroy_list(&eggs, NULL);
  destroy_map(get_map());
  destroy_event();
  destroy_module();
  exec_timer((time__**)-1, -133742);
}

void		module_delete(void *m)
{
  t_module	*module;
  int		i;

  i = -1;
  if (!(module = (t_module*)m))
    return ;
  free(module->name);
  free(module->delim);
  if (module->handle)
    dlclose(module->handle);
  while (module->functions[++i].action)
    free(module->functions[i].command);
  free(module);
}
