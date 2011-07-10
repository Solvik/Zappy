/*
** socket.h for Zappy in ./lib/network/include
** 
** Made by di-mar_j
** Login   <di-mar_j@epitech.net>
** 
** Started on  Thu Jun 23 22:12:26 2011 di-mar_j
** Last update Sun Jul 10 23:15:49 2011 di-mar_j
*/

#ifndef		SOCKET_H_
# define	SOCKET_H_

# include	<sys/time.h>
# include	<netdb.h>
# include	<netinet/in.h>
# include	<arpa/inet.h>

typedef struct protoent         proto;
typedef struct sockaddr_in      saddri;
typedef struct ifaddrs          ifaddrs;

typedef struct _ipv4	ipv4;
typedef struct _sock	sock;

/*
** This is Deprecated.
**   it was usefull in a another world
*/

#define IPV4            INET_ADDRSTRLEN
#define IPV6		INET6_ADDRSTRLEN
#define LO              "lo"
#define LOCALHOST       "127.0.0.1"
#define LOCAL(c)	(c && c[0] ? c[0]->ip : LOCALHOST)

typedef struct  _ipv4
{
  char  ip[IPV4];
  char  **split;
}               t_ipv4;

#if	defined(NETPRIVATE)
typedef struct _sock
{
  int           socket;
  int           port;

  int           queue;
  saddri        bind;
  proto         *pro;
}               t_sock;
#endif

#define PROTO   "TCP"

sock            *csocket(char *, int);
sock            *ssocket(int, int);
ipv4            **gethostipv4(void);
void            *socket_destroy(sock *);
void            *freeipv4(ipv4 **);

char*		socket_addr(sock *);
int		socket_port(sock *);
int		socket_fd(sock *);

void		socket_close(sock *);

#endif		/* !SOCKET_H_ */
