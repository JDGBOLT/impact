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
   Log_DBG("Config parsing start ticks: %i", SDL_GetTicks());
   Log_DBG("Config parsing end ticks: %i", SDL_GetTicks());
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
