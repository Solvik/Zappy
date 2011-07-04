/*
** scheduler.h for  in /home/di-mar_j/git/Zappy/server_zappy
** 
** Made by julien di-marco
** Login   <di-mar_j@epitech.net>
** 
** Started on  Wed Jun 29 14:55:10 2011 julien di-marco
** Last update Wed Jun 29 14:55:10 2011 julien di-marco
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
