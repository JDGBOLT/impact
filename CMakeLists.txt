# @file /CMakeLists.txt
# brief Primary CMake build system file, containing project settings and
# dependencies
# @author Joshua Gwinn (jdgbolt@gmail.com)
# @version
# @date 2011-01-28

# Base Project Properties
CMAKE_MINIMUM_REQUIRED(VERSION 2.6)
PROJECT(IMPACT)

# Version Information and other configuration settings
SET(Impact_VERSION_MAJOR 0)
SET(Impact_VERSION_MINOR 1)
SET(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${CMAKE_CURRENT_BINARY_DIR})

# Find the prerequisite libraries
FIND_PACKAGE(SDL REQUIRED)
FIND_PACKAGE(SDL_image REQUIRED)
FIND_PACKAGE(SDL_mixer REQUIRED)

# Print Error Messages if libraries weren't found
if (NOT SDL_FOUND)
   MESSAGE("Could not find SDL! Please ensure it is installed with development
   headers.")
endif (NOT SDL_FOUND)
if (NOT SDLMIXER_FOUND)
   MESSAGE("Could not find SDL_mixer! Please ensure it is installed with
   development headers.")
endif (NOT SDLMIXER_FOUND)
if (NOT SDLIMAGE_FOUND)
   MESSAGE("Could not find SDL_image! Please ensure it is installed with
   development headers.")
endif (NOT SDLIMAGE_FOUND)

# Include subdirectories in the tree for build process
ADD_SUBDIRECTORY(src)
