# @file CMakeLists.txt
# @brief CMake file for the /src/lib/libs directory
# @author Joshua Gwinn (jdgbolt@gmail.com)
# @version 
# @date 2012-02-02

# Add library subdirectories to the build system
ADD_SUBDIRECTORY(jansson)
ADD_SUBDIRECTORY(lz4)

# Set variable to add files to build process
SET(LIBS_SOURCES
   ${JANSSON_SOURCES}
   ${LZFOUR_SOURCES}
   PARENT_SCOPE)
