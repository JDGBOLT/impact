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
     return RETURN_QUIT;
   if (display_init(screen) != RETURN_NORMAL)
     return RETURN_QUIT;
   if (sound_init() != RETURN_NORMAL)
     return RETURN_QUIT;
   return RETURN_NORMAL;
}

void
ImpactInit::cleanup()
{
   display_cleanup();
   sound_cleanup();
   SDL_Quit();
}
