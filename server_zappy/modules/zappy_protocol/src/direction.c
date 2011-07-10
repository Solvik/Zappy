/*
** direction.h for  in /home/seb/git/Zappy/server_zappy/modules/zappy_protocol
**
** Made by seb
** Login   <seb@epitech.net>
**
** Started on  Sun Jul 10 06:53:39 2011 seb
** Last update Sun Jul 10 06:53:39 2011 seb
*/

#include "zappy_protocol.h"

int		get_sound_direction(int n, void *player)
{
  if (((t_player *)(player))->direction == NORTH)
    return ((n + 2) % 8);
  else if (((t_player *)(player))->direction == EAST)
    return ((n + 4) % 8);
  else if (((t_player *)(player))->direction == SOUTH)
    return ((n + 6) % 8);
  else  if (((t_player *)(player))->direction == WEST)
    return (n);
  return (0);
}

int		first_quad(int angle, void *player)
{
  int		dir;

  if (angle <= 25)
    dir = get_sound_direction(7, ((t_player *)(((t_fds *)player)->data)));
  else if (angle > 25 && angle <= 65)
    dir = get_sound_direction(6, ((t_player *)(((t_fds *)player)->data)));
  else
    dir = get_sound_direction(5, ((t_player *)(((t_fds *)player)->data)));
  return (dir);
}

int		second_quad(int angle, void *player)
{
  int		dir;

  if (angle <= 25)
    dir = get_sound_direction(7, ((t_player *)(((t_fds *)player)->data)));
  else if (angle > 25 && angle <= 65)
    dir = get_sound_direction(8, ((t_player *)(((t_fds *)player)->data)));
  else
    dir = get_sound_direction(1, ((t_player *)(((t_fds *)player)->data)));
  return (dir);
}

int		third_quad(int angle, void *player)
{
  int		dir;

  if (angle <= 25)
    dir = get_sound_direction(3, ((t_player *)(((t_fds *)player)->data)));
  else if (angle > 25 && angle <= 65)
    dir = get_sound_direction(4, ((t_player *)(((t_fds *)player)->data)));
  else
    dir = get_sound_direction(5, ((t_player *)(((t_fds *)player)->data)));
  return (dir);
}

int		fourth_quad(int angle, void *player)
{
  int		dir;

  if (angle <= 25)
    dir = get_sound_direction(3, ((t_player *)(((t_fds *)player)->data)));
  else if (angle > 25 && angle <= 65)
    dir = get_sound_direction(2, ((t_player *)(((t_fds *)player)->data)));
  else
    dir = get_sound_direction(1, ((t_player *)(((t_fds *)player)->data)));
  return (dir);
}
