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
#include <iostream>

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
        states.back()->init();
     }
   else
     return RETURN_ERROR;
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
     return RETURN_ERROR;
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
             std::cout << "States is empty!!" << std::endl;
             return RETURN_NORMAL;
          }
     }
   else
     {
        std::cout << "Could not open screen!" << std::endl;
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

Impact::~Impact()
{
   states_clear();
}
