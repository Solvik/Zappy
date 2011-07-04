/*
** event.h for  in /Users/Lifely/Developer/project/Zappy/server_zappy
** 
** Made by Julien Di Marco
** Login   <Lifely@epitech.net>
** 
** Started on  Mon Jul  4 04:34:30 2011 Julien Di Marco
** Last update Mon Jul  4 04:34:30 2011 Julien Di Marco
*/

#ifndef		EVENT_H_
# define	EVENT_H_

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
}		t_event;

typedef struct _catch
{
  char		*name;
  bool		(*call)(void *data);

  t_list	*catch;
}		t_catch;

#endif		/* !EVENT_H_ */
