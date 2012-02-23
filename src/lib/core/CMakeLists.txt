# @file CMakeLists.txt
# @brief CMake file for the /src/lib/core directory
# @author Joshua Gwinn (jdgbolt@gmail.com)
# @version 
# @date 2012-01-28

# Set variable to add files to build process
SET(CURDIR ${CMAKE_CURRENT_SOURCE_DIR})
SET(CORE_SOURCES
   "${CURDIR}/impact_init.cc"
   "${CURDIR}/impact_io.cc"
   "${CURDIR}/impact_io_lz4.cc"
   "${CURDIR}/impact_game.cc"
   "${CURDIR}/impact_state_play.cc"
   PARENT_SCOPE)


