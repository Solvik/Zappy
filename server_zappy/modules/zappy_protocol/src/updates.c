/*
** updates.c for  in /home/di-mar_j/git/Zappy/server_zappy/modules/zappy_protocol
** 
** Made by julien di-marco
** Login   <di-mar_j@epitech.net>
** 
** Started on  Sat Jul  9 15:51:18 2011 julien di-marco
** Last update Sat Jul  9 15:51:18 2011 julien di-marco
*/

#include	<unistd.h>
#include	<stdlib.h>
#include	<stdio.h>
#include	<math.h>

#include	"napi.h"
#include	"client.h"
#include	"zappy_protocol.h"

static double	timer_helper(double r)
{
  static double	dt = -1.0;
  double	o;

  if ((r == -1.0))
    {
      o = dt;
      dt = -1.0;
      return (o);
    }
  return ((dt = (r < dt || dt < 0.0 ? r : dt)));
}

static void	update_player(t_player *player, double *tdt)
{
  fds		c;
  double	dt;

  (void)tdt;
  if (!player)
    return ;
  c = player->client;
  dt = time_d(player->foodlt);
  player->foodlt = time_();
  player->foodt -= (dt / (((double)delay_life / get_delay()) * get_time()));
  player->food = (uint)abs(player->foodt);
  if (player->foodt <= 0)
    c ? (void)net_close_msg(c, "mort") : (void)player_destroy(player);
  if (player->foodt > 0)
    timer_helper(((player->foodt * delay_life) * (get_time() / get_delay())));
}

void	update_team(void *elem, void *arg)
{
  t_team	*team;

  if (!(team = (t_team*)elem) || !arg)
    return ;
  foreach_arg_list(team->players, (void (*)(void*, void*))update_player, arg);
}

#if	defined(NDEBUG)
#if	defined(NOTSHARED)
bool		zappy_update(double dt)
#else
bool		update(double dt)
#endif
{
  t_list	*teams;

  if (!(teams = get_teams()))
    return (false);
  foreach_arg_list(teams, update_team, (void*)&dt);
  return (true);
}
#endif

#if	defined(NOTSHARED)
double	zappy_timer(void)
#else
double	timer(void)
#endif
{
  return (timer_helper(-1));
}
