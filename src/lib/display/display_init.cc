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
     return RETURN_QUIT;
   *screen = SDL_SetVideoMode(screenWIDTH, screenHEIGHT, screenBPP, screenFLAGS);
   if (!screen)
     return RETURN_QUIT;
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
