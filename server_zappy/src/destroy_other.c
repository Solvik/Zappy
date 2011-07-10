/*
** destroy_other.c for  in /home/di-mar_j/git/Zappy/server_zappy
** 
** Made by julien di-marco
** Login   <di-mar_j@epitech.net>
** 
** Started on  Sun Jul 10 22:06:14 2011 julien di-marco
** Last update Sun Jul 10 22:06:14 2011 julien di-marco
*/

#include	<unistd.h>
#include	<stdlib.h>
#include	<stdio.h>
#include	<dlfcn.h>

#include	"exec.h"
#include	"event.h"
#include	"tserver.h"

extern t_server	*gserv;
void		module_delete(void *m);

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

void		destroy_module(void)
{
  if (!gserv)
    return ;
  destroy_list(&gserv->module, module_delete);
}
