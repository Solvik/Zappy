/*
** fds.h for  in /Users/Lifely/Developer/project/Zappy/lib/network/sources
** 
** Made by Julien Di Marco
** Login   <Lifely@epitech.net>
** 
** Started on  Sun Jul  3 15:12:31 2011 Julien Di Marco
** Last update Sun Jul  3 15:12:31 2011 Julien Di Marco
*/

#ifndef		FDS_H_
# define	FDS_H_

# include	"socket.h"
# include	"buffer.h"

typedef enum    e_fdtype
  {
    PROCRASTINATOR,
    READ,
    WRITE,
    RDWR,
    SERV
  }             fdtype;

#define DELIMS	64

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

typedef struct _fds	*fds;

fds             fds_add(fds *, int, int);
void		*fds_free(fds, void *(*)(void *));
void            *fds_remove(fds *, fds, void *(*)(void *));
void            *fds_destroy(fds *, void *(*)(void *));

int		fds_alive(fds);
void		fds_close(fds);

int             solimit(fds);

#endif		/* !FDS_H_ */
