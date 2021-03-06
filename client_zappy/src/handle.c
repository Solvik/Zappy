/*
** handle.c for Zappy in ./client_zappy/src
** 
** Made by di-mar_j
** Login   <di-mar_j@epitech.net>
** 
** Started on  Thu Jun 23 22:12:26 2011 di-mar_j
** Last update Sun Jul 10 23:15:49 2011 di-mar_j
*/

#include		"time_.h"
#include		"client_zappy.h"

static void		handle_mouse(t_visu *v, SDL_Event *event)
{
  static int space = 0;

  if ((event->type == SDL_KEYDOWN && event->key.keysym.sym == SDLK_ESCAPE)
      || event->type == SDL_QUIT)
    exit(EXIT_SUCCESS);
  if ((event->type == SDL_KEYDOWN && event->key.keysym.sym == SDLK_SPACE))
    space = !space;
  if ((event->type == SDL_MOUSEMOTION) && !space)
    {
      v->camera.x = ((((float)(event->motion.x + 1) *
		       (float)((float)v->width * 64 /
			       (float)v->camera.w))) - v->camera.w / 2);
      v->camera.y = ((((float)event->motion.y + 1.0f) *
		      ((float)v->height * 64 /
		       (float)v->camera.h)) - (v->camera.h / 2));
    }
  if (event->type == SDL_MOUSEBUTTONDOWN && event->button.button == 1)
    {
      if (v->info)
  	SDL_FillRect(v->info, NULL, SDL_MapRGB(v->screen->format,
  					       253, 63, 146));
      draw_info(v);
      get_info((event->button.x + v->camera.x) / 64,
  	       (event->button.y + v->camera.y) / 64, v);
    }
}

  static void		sdl_manage(t_visu *v)
  {
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

  void			handle_event(t_fds **pooler, t_visu *v)
  {
    char		*cmd;
    t_cmd		*inc_cmd;
    SDL_Event	e;
    time__	tv;

    while (1)
      {
	while (SDL_PollEvent(&e))
	  handle_mouse(v, &e);
	pool(pooler, timeval_(&tv, 0.001));
	if (!(*pooler) || (*pooler && !fds_alive(*pooler)))
	  return ;
	while ((cmd = getcmd(*pooler)))
	  {
	    inc_cmd = parse_cmd(cmd);
	    if (!gere_cmd(*pooler, inc_cmd, v))
	      fprintf(stderr, "error unknown or wrong cmd %s\n", cmd);
	    free_cmd(inc_cmd);
	  }
	sdl_manage(v);
      }
  }
