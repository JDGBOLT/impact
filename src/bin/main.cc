/**
 * @file /src/bin/main.cc
 * @brief The main function for the game impact, containing the main loop
 * @author Joshua Gwinn (jdgbolt@gmail.com)
 * @version
 * @date 2012-01-28
 */

#include "impact.hh"
#include "core/impact_init.hh"
#include "core/impact_game.hh"

int
main(int argc, const char *argv[])
{
   SDL_Surface *screen = NULL;
   ImpactInit init;
   Impact impact;
   init.init(&screen);
   while (impact.input_update() != RETURN_QUIT)
     {
        impact.logic_process();
        impact.display_render(screen);
        impact.sound_play();
        impact.state_check();
     }
   init.cleanup();
   return 0;
}
