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
