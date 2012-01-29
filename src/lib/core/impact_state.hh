/*
 * @file impact_state.hh
 * @brief The header file for the ImpactState class, the base class of the core
 * state manager.
 * @author Joshua Gwinn (jdgbolt@gmail.com)
 * @date 2012-01-28
 */

#ifndef _IMPACT_STATE_HH_
#define _IMPACT_STATE_HH_

#include "impact.hh"
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
};
#endif

