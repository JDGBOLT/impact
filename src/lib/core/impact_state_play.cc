/**
 * @file impact_state_play.cc
 * @brief Source file of the ImpactPlay class, which is the core module of the
 * Play state, which is run during normal gameplay.
 * @author Joshua Gwinn (jdgbolt@gmail.com)
 * @version 
 * @date 2012-01-30
 */

#include "impact_state_play.hh"

ErrorReturn
ImpactPlay::init()
{
   return RETURN_NORMAL;
}

ErrorReturn
ImpactPlay::cleanup()
{
   return RETURN_NORMAL;
}

ErrorReturn
ImpactPlay::input_update(std::bitset<NUM_BUTTONS> *keys)
{
   return input.input_update(keys);
}

ErrorReturn
ImpactPlay::logic_process(std::bitset<NUM_BUTTONS> *keys)
{
   return RETURN_NORMAL;
}

ErrorReturn
ImpactPlay::display_render(SDL_Surface *screen)
{
   return RETURN_NORMAL;
}

ErrorReturn
ImpactPlay::sound_play()
{
   return RETURN_NORMAL;
}

ErrorReturn
ImpactPlay::run_pause()
{
   return RETURN_NORMAL;
}

ErrorReturn
ImpactPlay::run_unpause()
{
   return RETURN_NORMAL;
}

StateReturn
ImpactPlay::state_check()
{
   return STATE_NULL;
}

ImpactState *
ImpactPlay::state_change()
{
   return (ImpactState *)(new ImpactPlay);
}

ImpactPlay::ImpactPlay()
{
}

ImpactPlay::~ImpactPlay()
{
}
