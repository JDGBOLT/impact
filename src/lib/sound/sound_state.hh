/**
 * @file sound_state.hh
 * @brief Header file for the SoundState class, the base class for the sound
 * module of all states.
 * @author Joshua Gwinn (jdgbolt@gmail.com)
 * @version 
 * @date 2012-01-30
 */

#ifndef _SOUND_STATE_HH_
#define _SOUND_STATE_HH_

#include "impact.hh"

class
SoundState
{
 public:
    virtual ErrorReturn
       init() = 0;
    virtual ErrorReturn
       cleanup() = 0;
    virtual
       ~SoundState() {};
};

#endif
