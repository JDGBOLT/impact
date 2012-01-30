# @file CMakeLists.txt
# @brief CMake file for the /src/lib/display directory
# @author Joshua Gwinn (jdgbolt@gmail.com)
# @version 
# @date 2012-01-28

# Set variable to add files to build process
SET(CURDIR ${CMAKE_CURRENT_SOURCE_DIR})
SET(DISPLAY_SOURCES
   "${CURDIR}/display_init.cc"
   "${CURDIR}/display_state.cc"
   PARENT_SCOPE)


