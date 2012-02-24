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
#include "util/timer.hh"

int
main(int argc, const char *argv[])
{
   SDL_Surface *screen = NULL;
   ImpactInit init;
   Impact impact;
   Timer time, renderTime;
   if (init.init(&screen) > 0)
     return EXIT_FAILURE;
   impact.state_push((ImpactState *)(new ImpactPlay));
   while (impact.input_update() == RETURN_NORMAL)
     {
        time.time_start();
        impact.logic_process();
        if (!renderTime.time_started() || renderTime.time_ticks() > (1000 / frameRATE))
          {
             renderTime.time_start();
             impact.display_render(screen);
             impact.sound_play();
             impact.state_check();
          }
        if (time.time_ticks() < (1000 / logicFRAMErate) )
          SDL_Delay( (1000 / logicFRAMErate) - time.time_ticks());
     }
   init.cleanup();
   return EXIT_SUCCESS;
}
