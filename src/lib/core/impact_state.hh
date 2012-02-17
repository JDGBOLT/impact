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

#ifndef _IMPACT_STATE_HH_
#define _IMPACT_STATE_HH_

/*
 * @file impact_state.hh
 * @brief The header file for the ImpactState class, the base class of the core
 * state manager.
 * @author Joshua Gwinn (jdgbolt@gmail.com)
 * @date 2012-01-28
 */

#include "impact.hh"
#include "config/config_global.hh"
#include <bitset>

class
ImpactState
{
 public:
    virtual ErrorReturn
       init() = 0;
    virtual ErrorReturn
       cleanup() = 0;
    virtual ErrorReturn
       input_update(std::bitset<NUM_BUTTONS> *keys) = 0;
    virtual ErrorReturn
       logic_process(std::bitset<NUM_BUTTONS> *keys) = 0;
    virtual ErrorReturn
       display_render(SDL_Surface *screen) = 0;
    virtual ErrorReturn
       sound_play() = 0;
    virtual ErrorReturn
       run_pause() = 0;
    virtual ErrorReturn
       run_unpause() = 0;
    virtual StateReturn
       state_check() = 0;
    virtual ImpactState *
       state_change() = 0;
    virtual ~ImpactState() {};
    ConfigGlobal *config;
};
#endif

