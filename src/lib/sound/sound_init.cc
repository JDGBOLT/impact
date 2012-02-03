/**
 * @file sound_init.cc
 * @brief Source file of the sound functions of the ImpactInit class, which
 * handles the init and cleanup sequence for Impact
 * @author Joshua Gwinn (jdgbolt@gmail.com)
 * @version 
 * @date 2012-01-28
 */

#include "core/impact_init.hh"
#include "SDL/SDL_mixer.h"

ErrorReturn
ImpactInit::sound_init()
{
   if (SDL_InitSubSystem(SDL_INIT_AUDIO) < 0)
     {
        Log_CRIT("Could not initialize audio subsystem:");
        Log_CRIT(SDL_GetError());
        return RETURN_QUIT;
     }
   if (Mix_OpenAudio(soundFREQUENCY, soundFORMAT, soundCHANNELS, soundCHUNKsize) < 0)
     {
        Log_CRIT("Could not open audio device:");
        Log_CRIT(SDL_GetError());
        return RETURN_QUIT;
     }
   return RETURN_NORMAL;
}

void
ImpactInit::sound_cleanup()
{
   Mix_CloseAudio();
}
