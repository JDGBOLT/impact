# @file CMakeLists.txt
# @brief CMake file for the /src/lib/config directory
# @author Joshua Gwinn (jdgbolt@gmail.com)
# @version 
# @date 2012-02-14

# Set variable to add files to build process
SET(CURDIR ${CMAKE_CURRENT_SOURCE_DIR})
SET(CONFIG_SOURCES
   "${CURDIR}/config_global.cc"
   PARENT_SCOPE)


