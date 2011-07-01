/*
** callback.h for  in /home/di-mar_j/git/Zappy/server_zappy
** 
** Made by julien di-marco
** Login   <di-mar_j@epitech.net>
** 
** Started on  Thu Jun 30 15:51:50 2011 julien di-marco
** Last update Thu Jun 30 15:51:50 2011 julien di-marco
*/

#ifndef		CALLBACK_H_
# define	CALLBACK_H_

# include	<stdbool.h>
# include	"net.h"

typedef bool (*callback)(fds, char *, void*);

typedef struct _callback
{
  void		*data;
  callback	_call;
}		t_callback;

bool		callback_set(fds, callback, void *);
bool		callback_active(fds);
bool		callback_overide(fds, callback, void *);

bool		callback_handler(fds c, char *s);
bool		callback_(fds c, char*, double _);

#endif		/* !CALLBACK_H_ */

