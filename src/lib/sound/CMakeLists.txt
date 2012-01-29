# @file CMakeLists.txt
# @brief CMake file for the /src/lib/sound directory
# @author Joshua Gwinn (jdgbolt@gmail.com)
# @version 
# @date 2012-01-28

# Set variable to add files to build process
SET(CURDIR ${CMAKE_CURRENT_SOURCE_DIR})
SET(SOUND_SOURCES
   "${CURDIR}/sound_init.cc"
   PARENT_SCOPE)
