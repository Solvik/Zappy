/*
** select_.h for Zappy in ./lib/network/include
** 
** Made by di-mar_j
** Login   <di-mar_j@epitech.net>
** 
** Started on  Thu Jun 23 22:12:26 2011 di-mar_j
** Last update Sun Jul 10 23:15:49 2011 di-mar_j
*/

#if		defined(SELECT_)
# ifndef	SELECT__H_
#  define	SELECT__H_

#  include	<sys/select.h>
#  include	<sys/types.h>
#  include	<sys/time.h>

typedef	 struct	_pool
{
  fd_set	read;
  fd_set	write;
  fd_set	error;
  int		max;
  int		isset;
}		t_select;

int             handle_serv(fds*, fds);
int             handle_read(fds);
int             handle_write(fds);

int		pool_fill(fds, t_select*);
int		pool_exec(t_select *, struct timeval *);
int		pool_handle(fds*, t_select*);

# endif		/* !SELECT__H_ */
#endif
