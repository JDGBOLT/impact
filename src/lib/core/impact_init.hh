/**
 * @file impact_init.hh
 * @brief Contains the ImpactInit class, which handles initializing the Impact
 * and SDL subsystems.
 * @author Joshua Gwinn (jdgbolt@gmail.com)
 * @version
 * @date 2012-01-28
 */

#ifndef _IMPACT_INIT_HH_
#define _IMPACT_INIT_HH_

#include "impact.hh"

class
ImpactInit
{
 public:
    ErrorReturn
       init(SDL_Surface **screen);
    void
       cleanup();
 private:
    ErrorReturn
       display_init(SDL_Surface **screen);
    void
       display_cleanup();
    ErrorReturn
       sound_init();
    void
       sound_cleanup();
};
#endif
