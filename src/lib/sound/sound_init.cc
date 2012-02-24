/* vim:ts=8 sw=3 sts=3 expandtab cino=>5n-3f0^-2{2(0W1st0:
 * 
 * Copyright (C) 
 * 2012 - Joshua Gwinn (jdgbolt@gmail.com)
 * This program is free software; you can redistribute it and/or
 * modify it under the terms of the GNU General Public License
 * as published by the Free Software Foundation; either version 2
 * of the License, or (at your option) any later version.
 * 
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * included GNU General Public License file located in COPYING or at
 * http://www.gnu.org/licenses/gpl-2.0.html for more details.
 */

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
        Log_CRIT("Could not initialize audio subsystem: %s", SDL_GetError());
        return RETURN_QUIT;
     }
   if (Mix_OpenAudio(soundFREQUENCY, soundFORMAT, soundCHANNELS, soundCHUNKsize) < 0)
     {
        Log_CRIT("Could not open audio device: %s", SDL_GetError());
        return RETURN_QUIT;
     }
   return RETURN_NORMAL;
}

void
ImpactInit::sound_cleanup()
{
   Mix_CloseAudio();
}
