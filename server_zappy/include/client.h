/*
** client.h for  in /Users/Lifely/Developer/project/Zappy/server_zappy
** 
** Made by Julien Di Marco
** Login   <Lifely@epitech.net>
** 
** Started on  Thu Jun 30 05:08:26 2011 Julien Di Marco
** Last update Thu Jun 30 05:08:26 2011 Julien Di Marco
*/

#ifndef		CLIENT_H_
# define	CLIENT_H_

# include	"scheduler.h"
# include	"callback.h"
# include	"flood.h"

# include	"module.h"

typedef struct _client
{
  char		*command;
  t_scheduler	schedule;
  t_callback	callback;
  t_antiflood	flood;
  int		close;

  t_module	*_m;
}		t_client;

bool		flood_destroy(t_client *);
bool		scheduler_destroy(t_client *);

void		*destroy_client(t_client *);

#endif		/* !CLIENT_H_ */
