/*
** callback.h for Zappy in ./server_zappy/include
** 
** Made by di-mar_j
** Login   <di-mar_j@epitech.net>
** 
** Started on  Thu Jun 23 22:12:26 2011 di-mar_j
** Last update Sun Jul 10 23:15:49 2011 di-mar_j
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

