/*
** client_zappy.c for Zappy in ./client_zappy/src
** 
** Made by di-mar_j
** Login   <di-mar_j@epitech.net>
** 
** Started on  Thu Jun 23 22:12:26 2011 di-mar_j
** Last update Sun Jul 10 23:15:49 2011 di-mar_j
*/

#include	<unistd.h>
#include	<stdlib.h>
#include	<errno.h>
#include	<stdio.h>

#include	"network.h"
#include	"client_zappy.h"
#include	"time_.h"

void			quit()
{
  SDL_Quit();
  TTF_Quit();
}

static void            camerasetting_(t_visu *v)
{
  if (v->camera.x < ((-1 * SCROLL) * 20))
    v->camera.x = (-1 * SCROLL) * 20;
  if (v->camera.y < ((-1 * SCROLL) * 20))
    v->camera.y = (-1 * SCROLL) * 20;
  if (v->camera.x > ((v->width * 64 - v->camera.w) + (SCROLL * 20)))
    v->camera.x = (v->width * 64 - v->camera.w) + (SCROLL * 20);
  if (v->camera.y > ((v->height * 64 - v->camera.h) + (SCROLL * 20)))
    v->camera.y = (v->height * 64 - v->camera.h) + (SCROLL * 20);
  if (v->width * 64 < v->camera.w)
    v->camera.x = ((v->camera.w - v->width * 64) / 2) * -1;
  if (v->height * 64 < v->camera.h)
    v->camera.y = ((v->camera.h - v->height * 64) / 2) * -1;
}

void		create_window(t_visu *p)
{
  (void)p;
  if (SDL_Init(SDL_INIT_VIDEO) == -1)
    {
      fprintf(stderr, "Can't init SDL. We're going to die\n");
      exit(EXIT_FAILURE);
    }
  p->screen = SDL_SetVideoMode(WIDTH,
			       HEIGHT, 32, SDL_HWSURFACE | SDL_DOUBLEBUF);
  atexit(quit);
  SDL_EnableKeyRepeat(1, 1);
  SDL_WM_SetCaption("Zappy", NULL);
  p->camera.h = HEIGHT;
  p->camera.w = WIDTH;
  p->refresh = false;
}

bool		client_zappy(int ac, char *av[])
{
  t_visu	visu;
  t_fds		*pooler;

  pooler = NULL;
  memset(&visu, 0, sizeof(visu));
  camerasetting_(&visu);
  TTF_Init();
  visu.police = TTF_OpenFont("data/comic.ttf", 12);
  if (ac > 2)
    {
      create_window(&visu);
      add_co(&pooler, av[1], atoi(av[2]));
      handle_event(&pooler, &visu);
    }
  return (true);
}
