/*
** time_.h for  in /home/di-mar_j/git/Zappy/server_zappy
** 
** Made by julien di-marco
** Login   <di-mar_j@epitech.net>
** 
** Started on  Wed Jun 29 00:05:56 2011 julien di-marco
** Last update Wed Jun 29 00:05:56 2011 julien di-marco
*/

#ifndef		TIME__H_
# define	TIME__H_

typedef struct timeval	time__;
typedef double		_time;

double		time_(void);
double		time_d(double);

time__		*timeval_(time__ *t, double time);
double		timeval__(time__ *t);

#endif		/* !TIME__H_ */
