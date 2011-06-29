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

#include	<sys/time.h>
#include        <netdb.h>
#include        <netinet/in.h>
#include        <arpa/inet.h>

#if	defined(NETPRIVATE)
# include "buffer.h"
#endif

#define PROTO   "TCP"

#define IPV4            INET_ADDRSTRLEN
#define LO              "lo"
#define LOCALHOST       "127.0.0.1"
#define LOCAL(c) (c && c[0] ? c[0]->ip : LOCALHOST)

/*
**
*/

#define READM   16
#define READB   1024

#define WRITEB  1024
#define DELIMS	64

#define sends(a, b)     (writes(a, b, 1))
#define eof(a)          (writes(a, NULL, 1))
#define sendneof(a, b)  (writes(a, b, 0))

/*
** Types
**    & Struct
*/

typedef struct protoent         proto;
typedef struct sockaddr_in      saddri;
typedef struct ifaddrs          ifaddrs;

typedef enum    e_fdtype
  {
    PROCRASTINATOR,
    READ,
    WRITE,
    RDWR,
    SERV
  }             fdtype;

typedef struct  _ipv4
{
  char  ip[IPV4];
  char  **split;
}               t_ipv4;

typedef struct _sock
{
  int           fd;
  int           socket;
  int           port;

  int           queue;
  saddri        bind;
  proto         *pro;
}               t_sock;

typedef struct _ipv4	ipv4;
typedef struct _sock	sock;

typedef struct _buffer	*buffer;
typedef struct _fds	*fds;

typedef struct  _fds
{
  void          *data;
  time_t        time;

  void		*trick;
  fdtype        type;
  int           fd;
  int		port;
  sock          *s;

  buffer        read;
  buffer        write;
  char		delim[DELIMS + 1];
  char		anounce : 1;

  struct _fds	*prev;
  struct _fds	*next;
  struct _fds	*descent;
}               t_fds;

/*
** Functions
**
*/

extern void             *(*free_data)(void *data);

/* = Fds = */
fds             add_fd(fds *l, int fd, int type);
void            *remove_fds(fds *, fds e);
void            *free_fds(fds *l);

/* = Buffer = */
char            *fill_buffer(char *buffer, char *s);
void            *free_buffer(buffer *l);
int             move_buffer(buffer l, int i);
buffer          remove_buffer(buffer e);
int             size_buffer(buffer b);
buffer          add_buffer(buffer *l, char *s);
buffer          add_char(buffer *l, char c);

/* = net = */
sock            *csocket(char *hostname, int port);
sock            *ssocket(int port, int queue);
ipv4            **gethostipv4(void);
void            *free_socket(sock *ket);
int             solimit(fds fd);
void            *freeipv4(ipv4 **local);

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
