/**
 * @file display_state_play.hh
 * @brief Header file for the DisplayPlay class, which is the display module of
 * the Play state, which is run during normal gameplay.
 * @author Joshua Gwinn (jdgbolt@gmail.com)
 * @version 
 * @date 2012-01-30
 */

#ifndef _DISPLAY_STATE_PLAY_HH_
#define _DISPLAY_STATE_PLAY_HH_

#include "display_state.hh"

class
DisplayPlay : public DisplayState
{
 public:
    ErrorReturn
       init();
    ErrorReturn
       cleanup();
    ErrorReturn
       screen_draw();
    DisplayPlay();
    ~DisplayPlay();
};

#endif
