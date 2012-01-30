/**
 * @file sound_state_play.cc
 * @brief Source file for the SoundPlay class, which is the sound module of
 * the Play state, which is run during normal gameplay.
 * @author Joshua Gwinn (jdgbolt@gmail.com)
 * @version 
 * @date 2012-01-30
 */

#include "sound_state_play.hh"

SoundPlay::SoundPlay()
{
   init();
}

SoundPlay::~SoundPlay()
{
   cleanup();
}

ErrorReturn
SoundPlay::init()
{
   return RETURN_NORMAL;
}

ErrorReturn
SoundPlay::cleanup()
{
   return RETURN_NORMAL;
}

