/*
** enw.c for  in /home/solvik/tek2/proj/Zappy/client_zappy
**
** Made by solvik blum
** Login   <blum_s@epitech.net>
**
** Started on  Sun Jul 10 16:39:52 2011 solvik blum
** Last update Sun Jul 10 16:47:24 2011 solvik blum
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
