/*
** display.c for Zappy in ./tools
** 
** Made by di-mar_j
** Login   <di-mar_j@epitech.net>
** 
** Started on  Thu Jun 23 22:12:26 2011 di-mar_j
** Last update Sun Jul 10 23:15:49 2011 di-mar_j
*/

#include        <SDL/SDL.h>

#include        <unistd.h>
#include        <stdlib.h>
#include        <string.h>
#include        <errno.h>
#include        <stdio.h>

#include        "graphics.h"

static void            camerasetting_(t_graphics *lemi)
{
  if (lemi)
    {
      if (lemi->camera.x < ((-1 * SCROLL) * 20))
        lemi->camera.x = (-1 * SCROLL) * 20;
      if (lemi->camera.y < ((-1 * SCROLL) * 20))
        lemi->camera.y = (-1 * SCROLL) * 20;
      if (lemi->camera.x > ((lemi->board->w - lemi->camera.w) + (SCROLL * 20)))
        lemi->camera.x = (lemi->board->w - lemi->camera.w) + (SCROLL * 20);
      if (lemi->camera.y > ((lemi->board->h - lemi->camera.h) + (SCROLL * 20)))
        lemi->camera.y = (lemi->board->h - lemi->camera.h) + (SCROLL * 20);
      if (lemi->board->w < lemi->camera.w)
        lemi->camera.x = ((lemi->camera.w - lemi->board->w) / 2) * -1;
      if (lemi->board->h < lemi->camera.h)
        lemi->camera.y = ((lemi->camera.h - lemi->board->h) / 2) * -1;
    }
}

void            display_(t_graphics *lemipc)
{
  if (lemipc)
    {
      camerasetting_(lemipc);
      if (lemipc->state == 2)
        {
          SDL_FillRect(lemipc->window, NULL, \
                       SDL_MapRGB(lemipc->window->format, \
				  255, 255, 255));
          SDL_BlitSurface(lemipc->board, &lemipc->camera, \
			  lemipc->window, NULL);
        }
      SDL_Flip(lemipc->window);
    }
}

/*
** Called by lemipc_graphics
**
*/

static int		e_(t_graphics *lemi, SDL_Event *event)
{
  static int    space = 0;

  if (lemi && event)
    {
      if ((event->type == SDL_KEYDOWN && event->key.keysym.sym == SDLK_ESCAPE)
	  || event->type == SDL_QUIT)
	lemi->state = 0;
      if (event->type == SDL_KEYDOWN && event->key.keysym.sym == SDLK_SPACE)
	space = (space ? 0 : 1);
      if ((event->type == SDL_MOUSEMOTION) && \
	  (!lemi->keys[SDLK_LSHIFT] && !space))
	{
	  lemi->camera.x = ((((float)(event->motion.x + 1) *	\
			      (float)((float)lemi->board->w /	\
				      (float)lemi->camera.w)))	\
			    - lemi->camera.w / 2);
	  lemi->camera.y = ((((float)event->motion.y + 1.0f) *	\
			     ((float)lemi->board->h /		\
			      (float)lemi->camera.h)) -		\
			    (lemi->camera.h / 2));
	}
      return (0);
    }
  return (-1);
}

int             event_(t_graphics *lemi)
{
  SDL_Event     event;

  if (lemi)
    {
      lemi->keys = SDL_GetKeyState(NULL);
      while (SDL_PollEvent(&event))
	e_(lemi, &event);
    }
  return ((lemi ? lemi->state : -1));
}

void            time_(t_graphics *lemi)
{
  unsigned int  pause;

  pause = 0;
  if (lemi)
    {
      if ((SDL_GetTicks() > ((lemi->time) + (1000.0f / (float)FPS))))
        {
          lemi->state = 2;
          lemi->time = SDL_GetTicks();
        }
      else
        {
          pause = (((lemi->time) + (1000.0f / (float)FPS)) \
                   - SDL_GetTicks());
          SDL_Delay(pause > 0 ? pause : 0);
          lemi->state = 1;
        }
    }
}
