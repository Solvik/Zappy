/*
** voir.c for  in /home/solvik/tek2/proj/Zappy/server_zappy/src
**
** Made by solvik blum
** Login   <blum_s@epitech.net>
**
** Started on  Mon Jun 13 12:46:13 2011 solvik blum
** Last update Wed Jun 29 17:12:59 2011 solvik blum
*/

#include <stdlib.h>
#include <string.h>
#include <math.h>

#include "player.h"
#include "server_zappy.h"
#include "tserver.h"

int		tr_x;
int		tr_y;

static void	send_broadcast(void *player)
{
  int		new_x;
  int		new_y;
  float		hyp;
  float		adj;
  float		angle;

  new_x = (((t_player *)(player))->x + tr_x - get_map_width() / 2) % get_map_width();
  new_y = (((t_player *)(player))->y + tr_y - get_map_height() / 2) % get_map_height();
  printf("player_x = %d player_y = %d new_x = %d new_y = %d\n", ((t_player *)(player))->x,((t_player *)(player))->y, new_x, new_y);
  printf("translation x %d translation y %d\n", tr_x, tr_y);
  hyp = sqrt(pow(-new_x ,2) + pow(-new_y, 2));
  adj = abs(new_x);
  angle = acos(adj / hyp);
  angle = (angle * 180) / 3.1415;
  angle = 90 - (int)angle;
  printf("angle = %f\n", angle);
  if (0 == new_x || 0 == new_y)
    {
      if (0 == new_y && new_x < 0)
	printf("p1\n");
      if (0 == new_y && new_x > 0)
	printf("p5\n");
      if (0 == new_x && new_y > 0)
	printf("p3\n");
      if (0 == new_x && new_y < 0)
	printf("p7\n");
    }
  else
    {
      if (new_x <= 0 && new_y >= 0)
	{
	  if (angle <= -25)
	    printf("3\n");
	  else if (angle > -25 && angle <= -65)
	    printf("2\n");
	  else
	    printf("1\n");
	}
      else if (new_x <= 0 && new_y <= 0)
	{
	  if (angle >= -25)
	    printf("1\n");
	  else if (angle < -25 && angle >= -65)
	    printf("8\n");
	  else
	    printf("7\n");
	}
      else if (new_x >= 0 && new_y >= 0)
	{
	  if (angle <= 25)
	    printf("3\n");
	  else if (angle > 25 && angle <= 65)
	    printf("4\n");
	  else
	    printf("5\n");
	}
      else
	{
	  if (angle <= 25)
	    printf("7\n");
	  else if (angle > 25 && angle <= 65)
	    printf("6\n");
	  else
	    printf("5\n");
	}
    }
}

int		zappy_broadcast(t_fds *client, char *cmd)
{
  uint		x;
  uint		y;
  char		*text;
  t_list	*players;

  (void)strtok(cmd, " ");
  text = strtok(NULL, " ");

  tr_x = get_map_width() / 2 - player_data->x;
  tr_y = get_map_height() / 2 - player_data->y;

  x = 0;
  printf("LOLOLOLOL\n");
  while (x < get_map_width())
    {
      y = 0;
      while (y < get_map_height())
	{
	  players = get_box_players(x, y);
	  if (players)
	    foreach_list(players, send_broadcast);
	  y++;
	}
      x++;
    }
  sends(client, "ok");
  return (1);
}
