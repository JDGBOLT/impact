/* Copyright (C) 
 * 2012 - Joshua Gwinn (jdgbolt@gmail.com)
 * This program is free software; you can redistribute it and/or
 * modify it under the terms of the GNU General Public License
 * as published by the Free Software Foundation; either version 2
 * of the License, or (at your option) any later version.
 * 
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 * 
 * You should have received a copy of the GNU General Public License
 * along with this program; if not, write to the Free Software
 * Foundation, Inc., 59 Temple Place - Suite 330, Boston, MA  02111-1307, USA.
 * 
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
