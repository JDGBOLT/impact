/**
 * @file impact.hh
 * @brief Primary header used by impact, containing global variables that will
 * not change
 * @author Joshua Gwinn (jdgbolt@gmail.com)
 * @version
 * @date 2011-01-28
 */

#ifndef _IMPACT_HH
#define _IMPACT_HH

// Global includes
#include "SDL/SDL.h"

// Constants

const int screenWIDTH = 800;
const int screenHEIGHT = 480;
const int screenBPP = 8;
const int frameRATE = 60;
const int logicFRAMErate = 120;
const int colorkeyR = 0xFF;
const int colorkeyG = 0;
const int colorkeyB = 0xFF;
static const char* gameNAME = "Impact";
const Uint32 screenFLAGS = SDL_HWSURFACE | SDL_HWPALETTE;
const Uint32 colorkeyFLAGS = SDL_SRCCOLORKEY | SDL_RLEACCEL;

// Sound parameters
const int soundFREQUENCY = 44100;
const Uint32 soundFORMAT = AUDIO_S16SYS;
const int soundCHANNELS = 2;
const int soundCHUNKsize = 4096;

// Defines

// Enumerations
enum
ErrorReturn
{
   RETURN_NORMAL=0,
   RETURN_ERROR,
   RETURN_QUIT
};

enum
StateReturn
{
   STATE_NULL=0,
   STATE_POP,
   STATE_PUSH,
   STATE_SET,
   STATE_CHANGE,
   STATE_MULTI,
   STATE_MULTI_POP,
   STATE_MULTI_PUSH,
   STATE_MULTI_SET,
   STATE_MULTI_CHANGE
};

enum 
Buttons
{
   BUTTON_A=0,
   BUTTON_B,
   BUTTON_X,
   BUTTON_Y,
   BUTTON_R,
   BUTTON_L,
   BUTTON_UP,
   BUTTON_DOWN,
   BUTTON_LEFT,
   BUTTON_RIGHT,
   BUTTON_START,
   BUTTON_SELECT,
   NUM_BUTTONS
};

enum
KeyStates
{
   UNPRESSED=0,
   PRESSED
};

enum
ObjectStates
{
   IS_FALLING=0,
   IS_MOVING,
   NUM_OBJECT_STATES
};

enum
ObjectHeading
{
   LEFT=0,
   RIGHT
};

// Handle debug logging
#define Log_OUT(STREAM, LEVEL, MESSAGE) fprintf(STREAM, "%s: %s:%i: %s\n", LEVEL, __FILE__, __LINE__, MESSAGE)
#define Log_CRIT(MESSAGE) Log_OUT(stderr, "CRIT", MESSAGE)
#ifndef NDEBUG
#define Log_ERR(MESSAGE) Log_OUT(stderr, "ERR", MESSAGE)
#define Log_INFO(MESSAGE) Log_OUT(stdout, "INFO", MESSAGE)
#define Log_WARN(MESSAGE) Log_OUT(stdout, "WARN", MESSAGE)
#define Log_DBG(MESSAGE) Log_OUT(stdout, "DBG", MESSAGE)
#else
#define Log_ERR(MESSAGE)
#define Log_INFO(MESSAGE)
#define Log_WARN(MESSAGE)
#define Log_DBG(MESSAGE)
#endif

#endif
