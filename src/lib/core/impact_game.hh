/**
 * @file impact_game.hh
 * @brief Header file for the class Impact, which is the primary class which is
 * run from the main loop and controls the state running and keeping persistant
 * variables that states need to keep between state changes
 * @author Joshua Gwinn (jdgbolt@gmail.com)
 * @version
 * @date 2012-01-28
 */

#ifndef _IMPACT_GAME_HH_
#define _IMPACT_GAME_HH_

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

