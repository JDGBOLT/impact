/**
 * @file display_state_play.cc
 * @brief Source file for the DisplayPlay class, which is the display module of
 * the Play state, which is run during normal gameplay.
 * @author Joshua Gwinn (jdgbolt@gmail.com)
 * @version 
 * @date 2012-01-30
 */

#include "display_state_play.hh"

DisplayPlay::DisplayPlay()
{
   init();
}

DisplayPlay::~DisplayPlay()
{
   cleanup();
}

ErrorReturn
DisplayPlay::init()
{
   return RETURN_NORMAL;
}

ErrorReturn
DisplayPlay::cleanup()
{
   return RETURN_NORMAL;
}

ErrorReturn
DisplayPlay::screen_draw()
{
   return RETURN_NORMAL;
}
