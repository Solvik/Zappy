/*
** event.h for Zappy in ./server_zappy/include
** 
** Made by di-mar_j
** Login   <di-mar_j@epitech.net>
** 
** Started on  Thu Jun 23 22:12:26 2011 di-mar_j
** Last update Sun Jul 10 23:15:49 2011 di-mar_j
*/

#ifndef		EVENT_H_
# define	EVENT_H_

# include	"list.h"

typedef	struct _eventManager
{
  t_list	*catch;
  t_list	*dispatch;
}		t_eventManager;

typedef	struct _event
{
  char		*name;
  void		*data;

  double	delay;
  char		relative : 1;
  char		free	 : 1;

  double	st;
  double	lt;
}		t_event;

typedef struct _catch
{
  char		*name;
  bool		(*call)(void *data);

  t_list	*catch;
}		t_catch;

bool		event_dispatch(char *, void *, double);
bool		event_free(char *, void *, double);
bool		event_relative_dispatch(char *, void *, double);
bool		event_free_dispatch(char *, void *, double);
bool		event_free_relative(char *, void *, double);

bool		event_catch(char *, bool (*)(void*));

double		event_update(double);
bool		eventm_dispatch(t_event *);

t_list		**singleton_event(void);

#endif		/* !EVENT_H_ */
