/* Copyright (C) 
 * 2012 - Joshua Gwinn (jdgbolt@gmail.com)
 * This program is free software; you can redistribute it and/or
 * modify it under the terms of the GNU General Public License
 * as published by the Free Software Foundation; either version 2
 * of the License, or (at your option) any later version.
 * 
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 * 
 * You should have received a copy of the GNU General Public License
 * along with this program; if not, write to the Free Software
 * Foundation, Inc., 59 Temple Place - Suite 330, Boston, MA  02111-1307, USA.
 * 
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
