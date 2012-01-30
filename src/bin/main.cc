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
#include "core/impact_state_play.hh"
#include "core/timer.hh"

int
main(int argc, const char *argv[])
{
   SDL_Surface *screen = NULL;
   ImpactInit init;
   Impact impact;
   Timer time;
   init.init(&screen);
   impact.state_push((ImpactState *)(new ImpactPlay));
   while (impact.input_update() == RETURN_NORMAL)
     {
        time.time_start();
        impact.logic_process();
        impact.display_render(screen);
        impact.sound_play();
        impact.state_check();
        if (time.time_ticks() < (1000 / frameRATE) )
          SDL_Delay( (1000 / frameRATE) - time.time_ticks());
     }
   init.cleanup();
   return 0;
}
