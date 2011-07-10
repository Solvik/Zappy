/*
** pfk.c for  in /home/solvik/tek2/proj/Zappy/client_zappy
**
** Made by solvik blum
** Login   <blum_s@epitech.net>
**
** Started on  Sun Jul 10 16:10:16 2011 solvik blum
** Last update Sun Jul 10 16:30:36 2011 solvik blum
*/

#include	<stdlib.h>
#include	"visu_func.h"
#include	"client_zappy.h"

int		visu_pfk(t_fds *pooler, t_cmd *cmd, t_visu *visu)
{
  t_player	*p;
  SDL_Rect	pos;
  SDL_Surface	*img;

  (void)pooler;
  if (!(p = get_player_by_id(visu, atoi(cmd->argv[1]))))
    return (0);
  pos.y = 64 * ((t_player *)p)->y;
  pos.x = 64 * ((t_player *)p)->x;
  img = SDL_LoadBMP("egg.bmp");
  if (!img)
    return (0);
  SDL_SetColorKey(img, SDL_SRCCOLORKEY, SDL_MapRGB(img->format, 0, 0, 0));
  SDL_BlitSurface(img, NULL, visu->draw, &pos);
  SDL_FreeSurface(img);
  return (1);
}
