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
 * @file display_init.cc
 * @brief Source file for the display functions of the ImpactInit class, which
 * handles the initialization for Impact
 * @author Joshua Gwinn (jdgbolt@gmail.com)
 * @version 
 * @date 2012-01-28
 */

#include "core/impact_init.hh"

ErrorReturn
ImpactInit::display_init(SDL_Surface **screen)
{
   if (SDL_InitSubSystem(SDL_INIT_VIDEO) < 0)
     {
        Log_CRIT("Could not initialize SDL video subsystem: %s", SDL_GetError());
        return RETURN_QUIT;
     }
   *screen = SDL_SetVideoMode(screenWIDTH, screenHEIGHT, screenBPP, screenFLAGS);
   if (!screen)
     {
        Log_CRIT("Could not open display: %s", SDL_GetError());
        return RETURN_QUIT;
     }
   if (screenBPP == 8)
     {
        SDL_Color colors[256];
        for (int i=0; i<256; i++)
          {
             colors[i].r = i;
             colors[i].g = i;
             colors[i].b = i;
          }
        SDL_SetColors(*screen, colors, 0, 256);
     }
   SDL_WM_SetCaption(gameNAME, NULL);
   return RETURN_NORMAL;
}

void
ImpactInit::display_cleanup()
{
}
