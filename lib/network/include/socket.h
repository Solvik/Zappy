/*
** socket.h for  in /Users/Lifely/Developer/project/Zappy/lib/network/sources
** 
** Made by Julien Di Marco
** Login   <Lifely@epitech.net>
** 
** Started on  Sun Jul  3 15:16:20 2011 Julien Di Marco
** Last update Sun Jul  3 15:16:20 2011 Julien Di Marco
*/

#ifndef		SOCKET_H_
# define	SOCKET_H_

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
  int           fd;
  int           socket;
  int           port;

  int           queue;
  saddri        bind;
  proto         *pro;
}               t_sock;
#endif

#define PROTO   "TCP"

sock            *csocket(char *hostname, int port);
sock            *ssocket(int port, int queue);
ipv4            **gethostipv4(void);
void            *free_socket(sock *ket);
void            *freeipv4(ipv4 **local);

#endif		/* !SOCKET_H_ */
