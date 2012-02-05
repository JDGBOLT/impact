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

#ifndef _IMPACT_HH
#define _IMPACT_HH

/**
 * @file impact.hh
 * @brief Primary header used by impact, containing global variables that will
 * not change
 * @author Joshua Gwinn (jdgbolt@gmail.com)
 * @version
 * @date 2011-01-28
 */

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
static const char* dataDIR = "data/";

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
#define Log_OUT(STREAM, LEVEL, ...) fprintf(STREAM, "%s: %s:%i: ", LEVEL, __FILE__, __LINE__); fprintf(STREAM, ## __VA_ARGS__); fprintf(STREAM, "\n")
#define Log_CRIT(...) Log_OUT(stderr, "CRIT", ## __VA_ARGS__)
#ifndef NDEBUG
#define Log_ERR(...) Log_OUT(stderr, "ERR", ## __VA_ARGS__)
#define Log_INFO(...) Log_OUT(stdout, "INFO", ## __VA_ARGS__)
#define Log_WARN(...) Log_OUT(stdout, "WARN", ## __VA_ARGS__)
#define Log_DBG(...) Log_OUT(stdout, "DBG", ## __VA_ARGS__)
#else
#define Log_ERR(...)
#define Log_INFO(...)
#define Log_WARN(...)
#define Log_DBG(...)
#endif

#endif
