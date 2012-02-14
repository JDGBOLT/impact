# @file CMakeLists.txt
# @brief CMake file for the /src/lib/libs/lz4 directory
# @author Joshua Gwinn (jdgbolt@gmail.com)
# @version 
# @date 2012-02-02

SET(LZFOUR_SOURCES)

# Set variable to add files to build process
SET(CURDIR ${CMAKE_CURRENT_SOURCE_DIR})
SET(LZFOUR_SOURCES
   "${CURDIR}/lz4.c"
   PARENT_SCOPE)
