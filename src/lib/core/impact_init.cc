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
 * @file impact_init.cc
 * @brief Source file for the core functions of the ImpactInit class, which handles the
 * initialization of the game Impact
 * @author Joshua Gwinn (jdgbolt@gmail.com)
 * @version 
 * @date 2012-01-28
 */

#include "impact_init.hh"

ErrorReturn
ImpactInit::init(SDL_Surface **screen)
{
   if (SDL_Init(SDL_INIT_TIMER) < 0)
     {
        Log_CRIT("Could not initialize SDL_TIMER: %s", SDL_GetError());
        return RETURN_QUIT;
     }
   if (display_init(screen) != RETURN_NORMAL)
     {
        Log_CRIT("Could not initialize the display!!!");
        return RETURN_QUIT;
     }
   if (sound_init() != RETURN_NORMAL)
     {
        Log_CRIT("Could not initialize the sound system!!!");
        return RETURN_QUIT;
     }
   return RETURN_NORMAL;
}

void
ImpactInit::cleanup()
{
   display_cleanup();
   sound_cleanup();
   SDL_Quit();
}
