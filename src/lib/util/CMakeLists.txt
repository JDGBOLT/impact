# @file CMakeLists.txt
# @brief CMake file for the /src/lib/util directory
# @author Joshua Gwinn (jdgbolt@gmail.com)
# @version 
# @date 2012-02-23

# Set variable to add files to build process
SET(CURDIR ${CMAKE_CURRENT_SOURCE_DIR})
SET(UTIL_SOURCES
   "${CURDIR}/timer.cc"
   PARENT_SCOPE)


