/*
** select_.h for  in /Users/Lifely/Developer/project/Zappy/lib/network/sources
** 
** Made by Julien Di Marco
** Login   <Lifely@epitech.net>
** 
** Started on  Sun Jul  3 17:00:10 2011 Julien Di Marco
** Last update Sun Jul  3 17:00:10 2011 Julien Di Marco
*/

#if		defined(SELECT_)
# ifndef	SELECT__H_
#  define	SELECT__H_

# include	<sys/select.h>
# include	<sys/types.h>
# include	<sys/time.h>

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
