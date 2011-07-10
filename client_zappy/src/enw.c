/*
** enw.c for Zappy in ./client_zappy/src
** 
** Made by di-mar_j
** Login   <di-mar_j@epitech.net>
** 
** Started on  Thu Jun 23 22:12:26 2011 di-mar_j
** Last update Sun Jul 10 23:15:49 2011 di-mar_j
*/

#include	<stdlib.h>
#include	"visu_func.h"
#include	"client_zappy.h"

int		visu_enw(t_fds *pooler, t_cmd *cmd, t_visu *visu)
{
  SDL_Rect	pos;
  SDL_Surface	*img;

  (void)pooler;
  pos.y = 64 * atoi(cmd->argv[4]);
  pos.x = 64 * atoi(cmd->argv[3]);
  img = SDL_LoadBMP("data/egg.bmp");
  if (!img)
    return (0);
  SDL_SetColorKey(img, SDL_SRCCOLORKEY, SDL_MapRGB(img->format, 0, 0, 0));
  SDL_BlitSurface(img, NULL, visu->draw, &pos);
  SDL_FreeSurface(img);
  return (1);
}
