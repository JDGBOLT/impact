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
