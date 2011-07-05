/*
** event.h for  in /Users/Lifely/Developer/project/Zappy/server_zappy
**
** Made by Julien Di Marco
** Login   <Lifely@epitech.net>
**
** Started on  Mon Jul  4 04:34:30 2011 Julien Di Marco
** Last update Tue Jul  5 18:03:18 2011 solvik blum
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
