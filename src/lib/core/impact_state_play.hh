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

#ifndef _IMPACT_STATE_PLAY_HH_
#define _IMPACT_STATE_PLAY_HH_

/**
 * @file impact_state_play.hh
 * @brief Header file for the ImpactPlay class, which is the core module of the
 * Play state, which is run during normal gameplay.
 * @author Joshua Gwinn (jdgbolt@gmail.com)
 * @version 
 * @date 2012-01-30
 */

#include "core/impact_state.hh"
#include "input/input_state_play.hh"
#include "logic/logic_state_play.hh"
#include "display/display_state_play.hh"
#include "sound/sound_state_play.hh"

class
ImpactPlay : ImpactState
{
 public:
    ErrorReturn
       init();
    ErrorReturn
       cleanup();
    ErrorReturn
       input_update(std::bitset<NUM_BUTTONS> *keys);
    ErrorReturn
       logic_process(std::bitset<NUM_BUTTONS> *keys);
    ErrorReturn
       display_render(SDL_Surface *screen);
    ErrorReturn
       sound_play();
    ErrorReturn
       run_pause();
    ErrorReturn
       run_unpause();
    StateReturn
       state_check();
    ImpactState *
       state_change();
    ImpactPlay();
    ~ImpactPlay();
 private:
    InputPlay input;
    LogicPlay logic;
    DisplayPlay display;
    SoundPlay sound;
};

#endif
