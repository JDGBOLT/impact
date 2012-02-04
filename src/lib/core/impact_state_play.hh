/**
 * @file impact_state_play.hh
 * @brief Header file for the ImpactPlay class, which is the core module of the
 * Play state, which is run during normal gameplay.
 * @author Joshua Gwinn (jdgbolt@gmail.com)
 * @version 
 * @date 2012-01-30
 */

#ifndef _IMPACT_STATE_PLAY_HH_
#define _IMPACT_STATE_PLAY_HH_

#include "core/impact_state.hh"
#include "input/input_state_play.hh"
#include "logic/logic_state_play.hh"
#include "display/display_state_play.hh"
#include "sound/sound_state_play.hh"
#include "core/impact_loader.hh"
#include "core/entity_tilemap.hh"

class
ImpactPlay : ImpactState
{
 public:
    ErrorReturn
       init();
    ErrorReturn
       cleanup();
    ErrorReturn
       input_update(std::bitset<NUM_BUTTONS> *keys);
    ErrorReturn
       logic_process(std::bitset<NUM_BUTTONS> *keys);
    ErrorReturn
       display_render(SDL_Surface *screen);
    ErrorReturn
       sound_play();
    ErrorReturn
       run_pause();
    ErrorReturn
       run_unpause();
    StateReturn
       state_check();
    ImpactState *
       state_change();
    ImpactPlay();
    ~ImpactPlay();
 private:
    InputPlay input;
    LogicPlay logic;
    DisplayPlay display;
    SoundPlay sound;
    ImpactLoader loader;
    EntityTilemap tileMap;
};

#endif
