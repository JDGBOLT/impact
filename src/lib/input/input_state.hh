/**
 * @file input_state.hh
 * @brief Header file of the InputState module, which is the base class of all
 * input module states
 * @author Joshua Gwinn (jdgbolt@gmail.com)
 * @version 
 * @date 2012-01-29
 */

#ifndef _INPUT_STATE_HH_
#define _INPUT_STATE_HH_

#include "impact.hh"
#include <bitset>

class
InputState
{
 public:
    ErrorReturn
       input_update(std::bitset<NUM_BUTTONS> *keys);
 protected:
    SDL_Event event;
};

#endif
