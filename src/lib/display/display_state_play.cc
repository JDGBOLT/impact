/* vim:ts=8 sw=3 sts=3 expandtab cino=>5n-3f0^-2{2(0W1st0:
 * 
 * Copyright (C) 
 * 2012 - Joshua Gwinn (jdgbolt@gmail.com)
 * This program is free software; you can redistribute it and/or
 * modify it under the terms of the GNU General Public License
 * as published by the Free Software Foundation; either version 2
 * of the License, or (at your option) any later version.
 * 
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * included GNU General Public License file located in COPYING or at
 * http://www.gnu.org/licenses/gpl-2.0.html for more details.
 */

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
