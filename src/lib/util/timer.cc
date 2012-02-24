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
 * @file timer.cc
 * @brief Source file for the Timer class, which provides basic timekeeping
 * functionality such as start and paused time.
 * @author Joshua Gwinn (jdgbolt@gmail.com)
 * @version 
 * @date 2012-01-29
 */

#include "SDL/SDL.h"
#include "timer.hh"

void
Timer::time_start()
{
   started = true;
   paused = false;
   startTicks = SDL_GetTicks();
}

void
Timer::time_stop()
{
   started = false;
   paused = false;
}

void
Timer::time_pause()
{
   if ( (started ==true) && (paused == false) )
     {
        paused = true;
        pausedTicks = SDL_GetTicks() - startTicks;
     }
}

void
Timer::time_unpause()
{
   if (paused == true)
     {
        paused = false;
        startTicks = SDL_GetTicks() - pausedTicks;
        pausedTicks = 0;
     }
}

int
Timer::time_ticks()
{
   if (started == true)
     {
        if (paused == true)
          return pausedTicks;
        else
          return SDL_GetTicks() - startTicks;
     }
   return 0;
}

bool
Timer::time_paused()
{
   return paused;
}

bool
Timer::time_started()
{
   return started;
}
