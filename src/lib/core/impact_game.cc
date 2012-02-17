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
 * @file impact_game.cc
 * @brief Source file for the Impact class, which is the primary class that
 * runs from the main loop, and handles state management and variables
 * persistent between states.
 * @author Joshua Gwinn (jdgbolt@gmail.com)
 * @version 
 * @date 2012-01-29
 */

#include "impact_game.hh"

ErrorReturn
Impact::state_change(ImpactState *state)
{
   if (!state)
     {
        if (!states.empty())
          {
             states.back()->cleanup();
             delete states.back();
             states.pop_back();
             states.push_back(state);
          }
        states.back()->config = &config;
        states.back()->init();
     }
   else
     {
        Log_WARN("Could not change state.");
        return RETURN_ERROR;
     }
   return RETURN_NORMAL;
}

ErrorReturn
Impact::state_pop()
{
   if (states.size() > 1)
     {
        states.back()->cleanup();
        delete states.back();
        states.pop_back();
        states.back()->run_unpause();
     }
   else
     {
        Log_WARN("Could not pop state.");
        return RETURN_ERROR;
     }
   return RETURN_NORMAL;
}

ErrorReturn
Impact::state_push(ImpactState *state)
{
   if (!states.empty())
     {
        states.back()->run_pause();
     }
   states.push_back(state);
   states.back()->config = &config;
   states.back()->init();
   return RETURN_NORMAL;
}

ErrorReturn
Impact::state_set(ImpactState *state)
{
   states_clear();
   state_push(state);
   return RETURN_NORMAL;
}

ErrorReturn
Impact::states_clear()
{
   if (!states.empty())
     {
        for (std::vector<ImpactState *>::iterator state = states.begin(); state != states.end();)
          {
             delete *state;
             state = states.erase(state);
          }
     }
   return RETURN_NORMAL;
}

ErrorReturn
Impact::input_update()
{
   if (!states.empty())
     return states.back()->input_update(&keys);
   else
     return RETURN_ERROR;
}

ErrorReturn
Impact::logic_process()
{
   if (!states.empty())
     return states.back()->logic_process(&keys);
   else
     return RETURN_ERROR;
}

ErrorReturn
Impact::display_render(SDL_Surface *screen)
{
   if (screen)
     {
        if (!states.empty())
          {
             ErrorReturn returnVal = states.back()->display_render(screen);
             if (returnVal == RETURN_NORMAL)
               SDL_Flip(screen);
             return returnVal;
          }
        else
          {
             Log_ERR("Could not render to screen, states empty!");
             return RETURN_NORMAL;
          }
     }
   else
     {
        Log_ERR("Could not open screen!");
        return RETURN_ERROR;
     }
   return RETURN_NORMAL;
}

ErrorReturn
Impact::sound_play()
{
   if (!states.empty())
     return states.back()->sound_play();
   else
     return RETURN_ERROR;
   return RETURN_NORMAL;
}

ErrorReturn
Impact::state_check()
{
   if (!states.empty())
     {
        switch (states.back()->state_check())
          {
           case STATE_CHANGE:
              return state_change(states.back()->state_change());
           case STATE_POP:
              return state_pop();
           case STATE_PUSH:
              return state_push(states.back()->state_change());
           case STATE_SET:
              return state_set(states.back()->state_change());
           case STATE_NULL:
              return RETURN_NORMAL;
           default:
              Log_WARN("State check recieved invalid return.");
          }
     }
   return RETURN_ERROR;
}

ErrorReturn
Impact::run_pause()
{
   if (!states.empty())
     return states.back()->run_pause();
   else
     return RETURN_ERROR;
}

ErrorReturn
Impact::run_unpause()
{
   if (!states.empty())
     return states.back()->run_unpause();
   else
     return RETURN_ERROR;
}

Impact::Impact()
{
   config.global_config_load();
}

Impact::~Impact()
{
   states_clear();
}
