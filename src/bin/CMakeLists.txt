# @file /src/bin/CMakeLists.txt
# @brief CMake file for the /src/bin directory
# @author Joshua Gwinn (jdgbolt@gmail.com)
# @version
# @date 2012-01-28

# Add libraries to link the main impact executable
LINK_LIBRARIES(
   ${SDL_LIBRARY}
   ${SDLIMAGE_LIBRARY}
   ${SDLMIXER_LIBRARY}
   SDLmain
)

# Build the impact executable
ADD_EXECUTABLE(
   impact
   WIN32
   MACOSX_BUNDLE
   impact.cc
   ${LIB_SOURCES}
)

# Build the lz4comp executable
ADD_EXECUTABLE(
   data/lz4comp
   WIN32
   MACOSX_BUNDLE
   lz4comp.cc
   "${CMAKE_SOURCE_DIR}/src/lib/core/impact_io_lz4.cc"
   "${CMAKE_SOURCE_DIR}/src/lib/libs/lz4/lz4.c"
)

INSTALL (TARGETS impact DESTINATION ${CMAKE_INSTALL_PREFIX})
