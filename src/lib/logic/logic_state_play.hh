/**
 * @file logic_state_play.hh
 * @brief Header file for the LogicPlay class, which is the logic module of
 * the Play state, which is run during normal gameplay.
 * @author Joshua Gwinn (jdgbolt@gmail.com)
 * @version 
 * @date 2012-01-30
 */

#ifndef _LOGIC_STATE_PLAY_HH_
#define _LOGIC_STATE_PLAY_HH_

#include "logic_state.hh"

class
LogicPlay : public LogicState
{
 public:
    ErrorReturn
       init();
    ErrorReturn
       cleanup();
    LogicPlay();
    ~LogicPlay();
};
#endif
