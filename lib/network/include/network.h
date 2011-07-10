/*
** network.h for Zappy in ./lib/network/include
** 
** Made by di-mar_j
** Login   <di-mar_j@epitech.net>
** 
** Started on  Thu Jun 23 22:12:26 2011 di-mar_j
** Last update Sun Jul 10 23:15:49 2011 di-mar_j
*/

#ifndef         NETWORK_H_
# define        NETWORK_H_

#  include	"fds.h"
#  include	"socket.h"
#  include	"buffer.h"

#  include	"select_.h"

/*
**
**
*/

#  define	READM		16
#  define	READB		1024
#  define	WRITEB		1024

#  define	sends(a, b)     (writes(a, b, 1))
#  define	eof(a)          (writes(a, NULL, 1))
#  define	sendneof(a, b)  (writes(a, b, 0))

typedef	struct	_pool		t_pool;

/*
** Functions
*/

void		error(char const *, ...);

char            *getcmd(fds);
void            writes(fds, char *, int);
int		sendf(fds, char const *, ...);
int		sendf_(fds, int, char const *, ...);

int             add_socket(fds *, int, int);
int             add_co(fds *, char *, int);

fds             pool(fds *, struct timeval *);

#endif          /* NETWORK_H_ */
