/* Copyright (C) 
 * 2012 - Joshua Gwinn (jdgbolt@gmail.com)
 * This program is free software; you can redistribute it and/or
 * modify it under the terms of the GNU General Public License
 * as published by the Free Software Foundation; either version 2
 * of the License, or (at your option) any later version.
 * 
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 * 
 * You should have received a copy of the GNU General Public License
 * along with this program; if not, write to the Free Software
 * Foundation, Inc., 59 Temple Place - Suite 330, Boston, MA  02111-1307, USA.
 * 
 */

#ifndef _DISPLAY_STATE_HH_
#define _DISPLAY_STATE_HH_

/**
 * @file display_state.hh
 * @brief Header file for the DisplayState class, which is the base class for
 * the display module of all states.
 * @author Joshua Gwinn (jdgbolt@gmail.com)
 * @version 
 * @date 2012-01-29
 */

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
