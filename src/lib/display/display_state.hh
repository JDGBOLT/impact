/**
 * @file display_state.hh
 * @brief Header file for the DisplayState class, which is the base class for
 * the display module of all states.
 * @author Joshua Gwinn (jdgbolt@gmail.com)
 * @version 
 * @date 2012-01-29
 */

#ifndef _DISPLAY_STATE_HH_
#define _DISPLAY_STATE_HH_

#include "impact.hh"
#include <string>

class
DisplayState
{
 public:
    SDL_Surface *
       image_load(std::string imageFilename);
    ErrorReturn
       surface_apply(int x, int y, SDL_Surface *source, SDL_Surface *destination, SDL_Rect *clip = NULL);
    virtual ErrorReturn
       screen_draw() = 0;
    virtual ErrorReturn
       init() = 0;
    virtual ErrorReturn
       cleanup() = 0;
    virtual
       ~DisplayState() {};
};

#endif
