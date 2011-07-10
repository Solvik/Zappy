/*
** sound.c for  in /home/seb/git/Zappy/client_zappy
**
** Made by seb
** Login   <seb@epitech.net>
**
** Started on  Sat Jul  9 17:05:52 2011 seb
** Last update Sat Jul  9 17:05:52 2011 seb
*/

#include	<unistd.h>
#include	<stdlib.h>

#include	<fmodex/fmod.h>
#include	<fmodex/fmod_errors.h>
#include	"client_zappy.h"

int		play_sound(t_fds *f, t_cmd *c, t_visu *v)
{
  static FMOD_SYSTEM *system = NULL;
  static FMOD_SOUND  *sound = NULL;
  FMOD_CHANNEL    *channel;
  FMOD_RESULT      result;

  (void)f;
  (void)c;
  (void)v;
  if (!system && (result = FMOD_System_Create(&system)) != FMOD_OK)
    return (1);
  if (!sound && (result = FMOD_System_Init(system, 2,
					   FMOD_INIT_NORMAL, NULL)) != FMOD_OK)
    return (1);
  if (!sound && (result = FMOD_System_CreateSound(system,
						  "data/nyan.wav",
						  FMOD_HARDWARE | FMOD_LOOP_OFF
						  | FMOD_2D, 0, &sound))
      != FMOD_OK)
    return (1);
  if ((result = FMOD_System_PlaySound(system,
				      FMOD_CHANNEL_FREE, sound, 0, &channel))
      != FMOD_OK)
    return (1);
  return (0);
}
