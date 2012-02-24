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

#ifndef _IMPACT_INIT_HH_
#define _IMPACT_INIT_HH_

/**
 * @file impact_init.hh
 * @brief Contains the ImpactInit class, which handles initializing the Impact
 * and SDL subsystems.
 * @author Joshua Gwinn (jdgbolt@gmail.com)
 * @version
 * @date 2012-01-28
 */

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
