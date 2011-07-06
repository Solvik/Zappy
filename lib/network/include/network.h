/*
** network.h for  in /home/di-mar_j//svn/irc/branches/network
**
** Made by julien di-marco
** Login   <di-mar_j@epitech.net>
**
** Started on  Tue Apr 19 16:46:45 2011 julien di-marco
** Last update Tue Apr 19 16:46:45 2011 julien di-marco
*/

#ifndef         NETWORK_H_
# define        NETWORK_H_

# include	"fds.h"
# include	"socket.h"
# include	"buffer.h"

# include	"select_.h"

/*
**
**
*/

#define READM   16
#define READB   1024

#define WRITEB  1024

#define sends(a, b)     (writes(a, b, 1))
#define eof(a)          (writes(a, NULL, 1))
#define sendneof(a, b)  (writes(a, b, 0))

typedef	struct _pool	t_pool;

/*
** Functions
*/

void		error(char const *format, ...);
extern void             *(*free_data)(void *data);

char            *getcmd(fds filed);

void            writes(fds filed, char *s, int end);

int             add_socket(fds *pool, int p, int q);
int             add_co(fds *pool, char *hostname, int p);

fds             pool(fds *, struct timeval *);

#endif          /* NETWORK_H_ */
