/*
** flood.h for Zappy in ./server_zappy/include
** 
** Made by di-mar_j
** Login   <di-mar_j@epitech.net>
** 
** Started on  Thu Jun 23 22:12:26 2011 di-mar_j
** Last update Sun Jul 10 23:15:49 2011 di-mar_j
*/

#ifndef         FLOOD_H_
# define        FLOOD_H_

# include       "network.h"

typedef struct  _antiflood
{
  char          **array;
  long          read;
  long          write;
  int           size;
}               t_antiflood;

char            *flood_check(fds, char *);
bool            flood_read(fds);

#endif          /* !FLOOD_H_ */
