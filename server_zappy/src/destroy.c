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

void		catcher_destroy(void *e)
{
  t_catch	*catch;

  if (!(catch = (t_catch*)e))
    return ;
  if (catch->name)
    free(catch->name);
  destroy_list(&catch->catch, catcher_destroy);
  free(catch);
}

void		dispatch_destroy(void *e)
{
  t_event	*evt;

  if (!(evt = (t_event*)e))
    return ;
  if (evt->name)
    free(evt->name);
  if (evt->free)
    free(evt->data);
  free(evt);
}

void		destroy_event(void)
{
  t_eventManager *em;

  if (!gserv)
    return ;
  em = &gserv->event;
  destroy_list(&em->catch, catcher_destroy);
  destroy_list(&em->dispatch, dispatch_destroy);
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

void		destroy_module(void)
{
  if (!gserv)
    return ;
  destroy_list(&gserv->module, module_delete);
}
