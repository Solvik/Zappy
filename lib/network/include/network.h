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

# include	<sys/time.h>
# include	<netdb.h>
# include	<netinet/in.h>
# include	<arpa/inet.h>

# include	"fds.h"
# include	"socket.h"
# include	"buffer.h"

#define READM   16
#define READB   1024

#define WRITEB  1024

#define sends(a, b)     (writes(a, b, 1))
#define eof(a)          (writes(a, NULL, 1))
#define sendneof(a, b)  (writes(a, b, 0))

/*
** Functions
*/

extern void             *(*free_data)(void *data);

/* = getcmd = */
char            *getcmd(fds filed);

/* = writeline = */
void            writes(fds filed, char *s, int end);

/* = network = */
int             handle_serv(fds *list, fds socket);
int             handle_read(fds socket);
int             handle_write(fds socket);
int             add_socket(fds *pool, int p, int q);
int             add_co(fds *pool, char *hostname, int p);

/* = pool = */
fds             pool(fds *, struct timeval *);

#endif          /* NETWORK_H_ */
