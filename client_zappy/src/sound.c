/*
** sound.c for  in /home/seb/git/Zappy/client_zappy
**
** Made by seb
** Login   <seb@epitech.net>
**
** Started on  Sat Jul  9 17:05:52 2011 seb
** Last update Sat Jul  9 17:05:52 2011 seb
*/

#include	<fmodex/fmod.h>
#include	"client_zappy.h"

int		play_sound(t_fds *f, t_cmd *c, t_visu *v)
{
  FMOD_SYSTEM *system;
  FMOD_SOUND *musique;

  (void)f;
  (void)c;
  (void)v;

  FMOD_System_Create(&system);
  FMOD_System_Init(system, 1, FMOD_INIT_NORMAL, NULL);
  FMOD_System_CreateSound(system, "nyan.wav", FMOD_SOFTWARE | FMOD_2D | FMOD_CREATESTREAM, 0, &musique);
  FMOD_Sound_SetLoopCount(musique, -1);
  FMOD_System_PlaySound(system, FMOD_CHANNEL_FREE, musique, 0, NULL);
  return (0);
}
