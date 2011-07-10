/*
** scheduler.h for Zappy in ./server_zappy/include
** 
** Made by di-mar_j
** Login   <di-mar_j@epitech.net>
** 
** Started on  Thu Jun 23 22:12:26 2011 di-mar_j
** Last update Sun Jul 10 23:15:49 2011 di-mar_j
*/

#ifndef		SCHEDULER_H_
# define	SCHEDULER_H_

# include	<stdbool.h>

# include	"network.h"
# include	"time_.h"

typedef struct	_scheduler
{
  void		*data;
  char		state	: 1;
  char		relative: 1;
  char		free	: 1;

  _time		st;
  _time		lt;
  _time		dt;
  bool		(*callback)(fds, void *);
}		t_scheduler;

bool		scheduler_(fds, double);
bool		scheduler_dispatch(fds);
double		scheduler_update(double);

bool		scheduler_action(fds, _time, bool (*_)(fds, void*), void *);
bool		scheduler_relative(fds, _time, bool (*_)(fds, void*), void *);

bool		scheduler_active(fds);
bool		scheduler_free(fds);

#endif		/* !SCHEDULER_H_ */
