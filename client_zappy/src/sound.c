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

typedef struct s_sound_data
{
  SDL_AudioSpec spec;
  Uint8 * sound;
  Uint32 soundlen;
  Uint32 soundpos;
}		t_sound;

void mixaudio(void *w, Uint8 *stream, int len)
{
  /* Uint8 *waveptr; */
  /* int    waveleft; */

  /* waveptr = ((t_sound *)w)->sound + ((t_sound *)w)->soundpos; */
  /* waveleft =  ((t_sound *)w)->soundlen -  ((t_sound *)w)->soundpos; */

  /* while ( waveleft <= len ) { */
  /*   SDL_memcpy(stream, waveptr, waveleft); */
  /*   stream += waveleft; */
  /*   len -= waveleft; */
  /*   waveptr =  ((t_sound *)w)->sound; */
  /*   waveleft =  ((t_sound *)w)->soundlen; */
  /* } */
  /* SDL_memcpy(stream, waveptr, len); */
  /* printf("pos = %u len = %u\n", ((t_sound *)w)->soundpos, ((t_sound *)w)->soundlen); */
  /* ((t_sound *)w)->soundpos += len; */
  /* if (((t_sound *)w)->soundpos >= ((t_sound *)w)->soundlen) */
  /*   { */
  /*     SDL_PauseAudio(1); */
  /*     /\* SDL_CloseAudio(); *\/ */
  /*     SDL_FreeWAV(((t_sound *)w)->sound); */
  /*   } */
  /* int i; */
  /* Uint32 amount; */
  /* printf("KIKOO\n"); */

  /* for ( i=0; i<NUM_SOUNDS; ++i ) { */
  /*   amount = (sounds[i].dlen-sounds[i].dpos); */
  /*   if ( amount > len ) { */
  /*     amount = len; */
  /*   } */
  /*   SDL_MixAudio(stream, &sounds[i].data[sounds[i].dpos], amount, SDL_MIX_MAXVOLUME); */
  /*   sounds[i].dpos += amount; */
  /* } */
}

void		play_sound()
{
  /* t_sound w; */

  /* if ( SDL_LoadWAV("./nyan.wav", */
  /* 		   &w.spec, &w.sound, &w.soundlen) == NULL ) */
  /*   { */
  /*     fprintf(stderr, "Couldn't load %s: %s\n", */
  /* 	      "nyan", SDL_GetError()); */
  /*     return; */
  /*   } */

  /* w.spec.callback = mixaudio; */
  /* w.spec.userdata = &w; */
  /* w.spec.samples = 512; */
  /* w.spec.freq  = 44100; */
  /* w.spec.channels = 2; */
  /* w.soundpos = 0; */

  /* if ( SDL_OpenAudio(&w.spec, NULL) < 0 ) */
  /*   { */
  /*     fprintf(stderr, "Couldn't open audio: %s\n", SDL_GetError()); */
  /*     SDL_FreeWAV(w.sound); */
  /*     return; */
  /*   } */
  /* SDL_PauseAudio(0); */
  /* int index; */
  /* SDL_AudioSpec wave; */
  /* Uint8 *data; */
  /* Uint32 dlen; */
  /* SDL_AudioCVT cvt; */

  /* wave.freq = 22050; */
  /* wave.channels = 2; */
  /* wave.samples = 512;        /\* A good value for games *\/ */
  /* wave.callback = mixaudio; */
  /* wave.userdata = NULL; */

  /* /\* Open the audio device and start playing sound! *\/ */

  /* /\* Look for an empty (or finished) sound slot *\/ */
  /* for ( index=0; index<NUM_SOUNDS; ++index ) { */
  /*   if ( sounds[index].dpos == sounds[index].dlen ) { */
  /*     break; */
  /*   } */
  /* } */
  /* if ( index == NUM_SOUNDS ) */
  /*   return; */

  /* /\* Load the sound file and convert it to 16-bit stereo at 22kHz *\/ */
  /* if ( SDL_LoadWAV("./nyan.wav", &wave, &data, &dlen) == NULL ) { */
  /*   fprintf(stderr, "Couldn't load %s: %s\n", "nyan", SDL_GetError()); */
  /*   return; */
  /* } */
  /* SDL_OpenAudio(&wave, NULL); */
  /* SDL_BuildAudioCVT(&cvt, wave.format, wave.channels, wave.freq, */
  /* 		    AUDIO_S16,   2,             22050); */
  /* cvt.buf = malloc(dlen*cvt.len_mult); */
  /* memcpy(cvt.buf, data, dlen); */
  /* cvt.len = dlen; */
  /* SDL_ConvertAudio(&cvt); */
  /* SDL_FreeWAV(data); */
  /* /\* Put the sound data in the slot (it starts playing immediately) *\/ */
  /* if ( sounds[index].data ) { */
  /*   free(sounds[index].data); */
  /* } */
  /* SDL_LockAudio(); */
  /* sounds[index].data = cvt.buf; */
  /* sounds[index].dlen = cvt.len_cvt; */
  /* sounds[index].dpos = 0; */
  /* SDL_UnlockAudio(); */
  FMOD_SYSTEM *system;
  FMOD_SOUND *musique;

  FMOD_System_Create(&system);
  FMOD_System_Init(system, 1, FMOD_INIT_NORMAL, NULL);
  FMOD_System_CreateSound(system, "nyan.wav", FMOD_SOFTWARE | FMOD_2D | FMOD_CREATESTREAM, 0, &musique);
  FMOD_Sound_SetLoopCount(musique, -1);
  FMOD_System_PlaySound(system, FMOD_CHANNEL_FREE, musique, 0, NULL);
}
