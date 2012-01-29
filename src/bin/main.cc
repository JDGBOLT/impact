/**
 * @file /src/bin/main.cc
 * @brief The main function for the game impact, containing the main loop
 * @author Joshua Gwinn (jdgbolt@gmail.com)
 * @version
 * @date 2012-01-28
 */

#include "impact.hh"
#include "core/impact_init.hh"

int
main(int argc, const char *argv[])
{
   SDL_Surface *screen = NULL;
   ImpactInit init;
   init.init(&screen);
   init.cleanup();
   return 0;
}
