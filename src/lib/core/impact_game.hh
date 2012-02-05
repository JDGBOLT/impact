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


#ifndef _IMPACT_GAME_HH_
#define _IMPACT_GAME_HH_

/**
 * @file impact_game.hh
 * @brief Header file for the class Impact, which is the primary class which is
 * run from the main loop and controls the state running and keeping persistant
 * variables that states need to keep between state changes
 * @author Joshua Gwinn (jdgbolt@gmail.com)
 * @version
 * @date 2012-01-28
 */

#include "impact.hh"
#include "core/impact_state.hh"
#include <vector>
#include <bitset>

class
Impact
{
 public:
    // Functions

    // State Change Functions
    ErrorReturn
       state_change(ImpactState *state);
    ErrorReturn
       state_pop();
    ErrorReturn
       state_push(ImpactState *state);
    ErrorReturn
       state_set(ImpactState *state);

    // Functions passed to state
    ErrorReturn
       input_update();
    ErrorReturn
       logic_process();
    ErrorReturn
       display_render(SDL_Surface *pScreen);
    ErrorReturn
       sound_play();
    ErrorReturn
       run_pause();
    ErrorReturn
       run_unpause();
    ErrorReturn
       state_check();
    ~Impact();

 private:
    ErrorReturn
       states_clear();
    std::vector<ImpactState *> states;
    std::bitset<NUM_BUTTONS> keys;
};
#endif

