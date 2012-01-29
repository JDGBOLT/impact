/**
 * @file input_state.cc
 * @brief Source file of the InputState class, base class for the input module
 * states
 * @author Joshua Gwinn (jdgbolt@gmail.com)
 * @version 
 * @date 2012-01-29
 */

#include "input_state.hh"

ErrorReturn
InputState::input_update(std::bitset<NUM_BUTTONS> *keys)
{
   while (SDL_PollEvent(&event))
     {
        switch (event.type)
          {
           case SDL_QUIT:
              return RETURN_QUIT;
           case SDL_KEYUP:
           case SDL_KEYDOWN:
                {
                   switch (event.key.keysym.sym)
                     {
                      case SDLK_UP: (*keys)[BUTTON_UP] =
                                    (event.type == SDL_KEYDOWN) ? PRESSED : UNPRESSED;
                                    break;
                      case SDLK_DOWN: (*keys)[BUTTON_DOWN] =
                                    (event.type == SDL_KEYDOWN) ? PRESSED : UNPRESSED;
                                    break;
                      case SDLK_LEFT: (*keys)[BUTTON_LEFT] =
                                    (event.type == SDL_KEYDOWN) ? PRESSED : UNPRESSED;
                                    break;
                      case SDLK_RIGHT: (*keys)[BUTTON_RIGHT] =
                                    (event.type == SDL_KEYDOWN) ? PRESSED : UNPRESSED;
                                    break;
#ifdef PANDORA
                      case SDLK_PAGEUP: (*keys)[BUTTON_Y] =
                                    (event.type == SDL_KEYDOWN) ? PRESSED : UNPRESSED;
                                    break;
                      case SDLK_PAGEDOWN: (*keys)[BUTTON_X] =
                                    (event.type == SDL_KEYDOWN) ? PRESSED : UNPRESSED;
                                    break;
                      case SDLK_HOME: (*keys)[BUTTON_A] =
                                    (event.type == SDL_KEYDOWN) ? PRESSED : UNPRESSED;
                                    break;
                      case SDLK_END: (*keys)[BUTTON_B] =
                                    (event.type == SDL_KEYDOWN) ? PRESSED : UNPRESSED;
                                    break;
                      case SDLK_RSHIFT: (*keys)[BUTTON_L] =
                                    (event.type == SDL_KEYDOWN) ? PRESSED : UNPRESSED;
                                    break;
                      case SDLK_RCTRL: (*keys)[BUTTON_R] =
                                    (event.type == SDL_KEYDOWN) ? PRESSED : UNPRESSED;
                                    break;
                      case SDLK_LALT: (*keys)[BUTTON_START] =
                                    (event.type == SDL_KEYDOWN) ? PRESSED : UNPRESSED;
                                    break;
                      case SDLK_LCTRL: (*keys)[BUTTON_SELECT] =
                                    (event.type == SDL_KEYDOWN) ? PRESSED : UNPRESSED;
                                    break;
                      default: break;
#else
                      case SDLK_w: (*keys)[BUTTON_Y] =
                                    (event.type == SDL_KEYDOWN) ? PRESSED : UNPRESSED;
                                    break;
                      case SDLK_s: (*keys)[BUTTON_X] =
                                    (event.type == SDL_KEYDOWN) ? PRESSED : UNPRESSED;
                                    break;
                      case SDLK_a: (*keys)[BUTTON_A] =
                                    (event.type == SDL_KEYDOWN) ? PRESSED : UNPRESSED;
                                    break;
                      case SDLK_d: (*keys)[BUTTON_B] =
                                    (event.type == SDL_KEYDOWN) ? PRESSED : UNPRESSED;
                                    break;
                      case SDLK_q: (*keys)[BUTTON_L] =
                                    (event.type == SDL_KEYDOWN) ? PRESSED : UNPRESSED;
                                    break;
                      case SDLK_e: (*keys)[BUTTON_R] =
                                    (event.type == SDL_KEYDOWN) ? PRESSED : UNPRESSED;
                                    break;
                      case SDLK_f: (*keys)[BUTTON_START] =
                                    (event.type == SDL_KEYDOWN) ? PRESSED : UNPRESSED;
                                    break;
                      case SDLK_g: (*keys)[BUTTON_SELECT] =
                                    (event.type == SDL_KEYDOWN) ? PRESSED : UNPRESSED;
                                    break;
                      default: break;
#endif
                     }
                }
           default: break;
          }
     }
   return RETURN_NORMAL;
}
