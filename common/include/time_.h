/*
** time_.h for Zappy in ./common/include
** 
** Made by di-mar_j
** Login   <di-mar_j@epitech.net>
** 
** Started on  Thu Jun 23 22:12:26 2011 di-mar_j
** Last update Sun Jul 10 23:15:49 2011 di-mar_j
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
