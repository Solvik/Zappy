/*
** client.h for Zappy in ./server_zappy/include
** 
** Made by di-mar_j
** Login   <di-mar_j@epitech.net>
** 
** Started on  Thu Jun 23 22:12:26 2011 di-mar_j
** Last update Sun Jul 10 23:15:49 2011 di-mar_j
*/

#ifndef		CLIENT_H_
# define	CLIENT_H_

# include	"scheduler.h"
# include	"callback.h"
# include	"flood.h"

# include	"module.h"

typedef struct	_client
{
  char		*command;
  t_scheduler	schedule;
  t_callback	callback;
  t_antiflood	flood;
  bool		close;

  t_module	*_m;
}		t_client;

bool		flood_destroy(t_client *);
bool		scheduler_destroy(t_client *);

void		*destroy_client(t_client *);

#endif		/* !CLIENT_H_ */
