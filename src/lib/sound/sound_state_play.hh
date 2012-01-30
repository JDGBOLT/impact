/**
 * @file sound_state_play.hh
 * @brief Header file for the SoundPlay class, which is the sound module of
 * the Play state, which is run during normal gameplay.
 * @author Joshua Gwinn (jdgbolt@gmail.com)
 * @version 
 * @date 2012-01-30
 */

#ifndef _SOUND_STATE_PLAY_HH_
#define _SOUND_STATE_PLAY_HH_

#include "sound_state.hh"

class
SoundPlay : public SoundState
{
 public:
    ErrorReturn
       init();
    ErrorReturn
       cleanup();
    SoundPlay();
    ~SoundPlay();
};
#endif
