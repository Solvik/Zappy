/*
** client_zappy.c for  in /Users/Lifely/Developer/project/Zappy/client_zappy
**
** Made by Julien Di Marco
** Login   <Lifely@epitech.net>
**
** Started on  Thu Jun 30 05:33:31 2011 Julien Di Marco
** Last update Sat Jul  9 18:51:06 2011 solvik blum
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
  if (v->camera.x > ((v->width * 32 - v->camera.w) + (SCROLL * 20)))
    v->camera.x = (v->width * 32 - v->camera.w) + (SCROLL * 20);
  if (v->camera.y > ((v->height * 32 - v->camera.h) + (SCROLL * 20)))
    v->camera.y = (v->height * 32 - v->camera.h) + (SCROLL * 20);
  if (v->width * 32 < v->camera.w)
    v->camera.x = ((v->camera.w - v->width * 32) / 2) * -1;
  if (v->height * 32 < v->camera.h)
    v->camera.y = ((v->camera.h - v->height * 32) / 2) * -1;
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

static void		handle_mouse(t_visu *v, SDL_Event *event)
{
  static int space = 0;

  if (event)
    {
      if ((event->type == SDL_KEYDOWN && event->key.keysym.sym == SDLK_ESCAPE)
      	  || event->type == SDL_QUIT)
      	exit(EXIT_SUCCESS);
      if ((event->type == SDL_KEYDOWN && event->key.keysym.sym == SDLK_SPACE))
	space = !space;
      if ((event->type == SDL_MOUSEMOTION) && !space)
	{
	  v->camera.x = ((((float)(event->motion.x + 1) *
			   (float)((float)v->width * 32 /
				   (float)v->camera.w))) - v->camera.w / 2);
	  v->camera.y = ((((float)event->motion.y + 1.0f) *
			  ((float)v->height * 32 /
			   (float)v->camera.h)) - (v->camera.h / 2));
	}
      if (event->type == SDL_MOUSEBUTTONDOWN && event->button.button == 1)
	{
	  if (v->info)
	    SDL_FillRect(v->info, NULL, SDL_MapRGB(v->screen->format, 0, 255, 0));
	  draw_info(v);
	  get_info((event->button.x + v->camera.x) / 32, (event->button.y + v->camera.y) / 32, v);
	}
      return;
    }
}

void		handle_event(t_fds **pooler, t_visu *v)
{
  char		*cmd;
  t_cmd		*inc_cmd;
  SDL_Event	e;
  time__	tv;

  while (1)
    {
      pool(pooler, timeval_(&tv, 0.001));
      if (!(*pooler) || (*pooler && !fds_alive(*pooler)))
	break;
      while ((cmd = getcmd(*pooler)))
	{
	  inc_cmd = parse_cmd(cmd);
	  if (!gere_cmd(*pooler, inc_cmd, v))
	    fprintf(stderr, "error unknown or wrong cmd %s\n", cmd);
	  free_cmd(inc_cmd);
	}
      while (SDL_PollEvent(&e))
	handle_mouse(v, &e);
      if (v->refresh)
	{
	  refresh_screen(v);
	  v->refresh = false;
	}
      SDL_FillRect(v->screen, NULL, SDL_MapRGB(v->screen->format,
					       255, 255, 255));
      if (v->draw)
	SDL_BlitSurface(v->draw, &v->camera, v->screen, NULL);
      if (v->info)
	SDL_BlitSurface(v->info, NULL, v->screen, NULL);
      SDL_Flip(v->screen);
    }
}

bool		client_zappy(int ac, char *av[])
{
  t_visu	visu;
  t_fds		*pooler;

  pooler = NULL;
  memset(&visu, 0, sizeof(visu));
  camerasetting_(&visu);
  TTF_Init();
  visu.police = TTF_OpenFont("./Comic Sans MS.ttf", 12);
  if (ac > 2)
    {
      create_window(&visu);
      add_co(&pooler, av[1], atoi(av[2]));
      handle_event(&pooler, &visu);
    }
  return (true);
}
