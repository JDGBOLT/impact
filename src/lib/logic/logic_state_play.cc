/**
 * @file logic_state_play.cc
 * @brief Source file for the LogicPlay class, which is the logic module of
 * the Play state, which is run during normal gameplay.
 * @author Joshua Gwinn (jdgbolt@gmail.com)
 * @version 
 * @date 2012-01-30
 */

#include "logic_state_play.hh"

LogicPlay::LogicPlay()
{
   init();
}

LogicPlay::~LogicPlay()
{
   cleanup();
}

ErrorReturn
LogicPlay::init()
{
   return RETURN_NORMAL;
}

ErrorReturn
LogicPlay::cleanup()
{
   return RETURN_NORMAL;
}

