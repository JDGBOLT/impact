# @file /src/lib/CMakeLists.txt
# @brief CMake file for the /src/lib directory
# @author Joshua Gwinn (jdgbolt@gmail.com)
# @version
# @date 2012-01-28

# Include subdirectories in the tree for build process
ADD_SUBDIRECTORY(util)
ADD_SUBDIRECTORY(core)
ADD_SUBDIRECTORY(display)
ADD_SUBDIRECTORY(sound)
ADD_SUBDIRECTORY(input)
ADD_SUBDIRECTORY(logic)
ADD_SUBDIRECTORY(libs)
ADD_SUBDIRECTORY(config)

# Set source variable to build main.cc in /src/bin
SET(LIB_SOURCES
   ${UTIL_SOURCES}
   ${CORE_SOURCES}
   ${DISPLAY_SOURCES}
   ${SOUND_SOURCES}
   ${INPUT_SOURCES}
   ${LOGIC_SOURCES}
   ${LIBS_SOURCES}
   ${CONFIG_SOURCES}
   PARENT_SCOPE)
