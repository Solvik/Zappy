/*
** draw.c for  in /home/seb/git/Zappy/client_zappy
**
** Made by seb
** Login   <seb@epitech.net>
**
** Started on  Thu Jul  7 14:09:16 2011 seb
** Last update Sat Jul  9 01:02:47 2011 Sebastien Blot
*/

#include "client_zappy.h"

void		refresh_screen(t_visu *v)
{
  draw_map(v);
  foreach_arg_list(v->player, draw_player, v);
  draw_info(v);
}

void		draw_info(t_visu *v)
{
  SDL_Rect pos;

  if (!v->info)
	v->info =  SDL_CreateRGBSurface(SDL_HWSURFACE | SDL_DOUBLEBUF, 800,  32, 32, 0, 0, 0, 0);
  pos.x = 0;
  pos.y = 600 - 32;
  SDL_FillRect(v->info, NULL, SDL_MapRGB(v->screen->format, 0, 255, 0));
}

void		draw_map(t_visu *v)
{
  SDL_Rect	pos;
  SDL_Surface	*img;
  int		x;
  int		y;

  x = 0;
  if (!v->draw)
	v->draw = SDL_CreateRGBSurface(SDL_HWSURFACE | SDL_DOUBLEBUF, v->width * 32, (v->height - 1) * 32, 32, 0, 0, 0, 0);
  img = SDL_LoadBMP("grass.bmp");
  while (x < v->width)
    {
      y = 0;
      while (y < v->height)
		{
		  pos.x = x * 32;
		  pos.y = y * 32;
		  SDL_BlitSurface(img, NULL, v->draw, &pos);
		  y++;
		}
      x++;
    }
  free(img);
}

void		draw_player(void *p, void *v)
{
  SDL_Rect pos;
  SDL_Surface *img;

  pos.y = 32 * ((t_player *)p)->y;
  pos.x = 32 * ((t_player *)p)->x;
  img = SDL_LoadBMP("blob.bmp");
  SDL_SetColorKey(img, SDL_SRCCOLORKEY, SDL_MapRGB(img->format, 0, 0, 0));
  SDL_BlitSurface(img, NULL, ((t_visu *)v)->draw, &pos);
  free(img);
}
