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

