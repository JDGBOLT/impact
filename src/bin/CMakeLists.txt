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
   main.cc
   ${LIB_SOURCES}
)

# Build the lz4comp executable
ADD_EXECUTABLE(
   data/lz4comp
   WIN32
   MACOSX_BUNDLE
   lz4comp.cc
   "${CMAKE_SOURCE_DIR}/src/lib/core/impact_io.cc"
   "${CMAKE_SOURCE_DIR}/src/lib/libs/lz4/lz4.c"
   "${CMAKE_SOURCE_DIR}/src/lib/libs/jansson/dump.c"
   "${CMAKE_SOURCE_DIR}/src/lib/libs/jansson/error.c"
   "${CMAKE_SOURCE_DIR}/src/lib/libs/jansson/hashtable.c"
   "${CMAKE_SOURCE_DIR}/src/lib/libs/jansson/load.c"
   "${CMAKE_SOURCE_DIR}/src/lib/libs/jansson/memory.c"
   "${CMAKE_SOURCE_DIR}/src/lib/libs/jansson/strbuffer.c"
   "${CMAKE_SOURCE_DIR}/src/lib/libs/jansson/strconv.c"
   "${CMAKE_SOURCE_DIR}/src/lib/libs/jansson/utf.c"
   "${CMAKE_SOURCE_DIR}/src/lib/libs/jansson/value.c"
)

INSTALL (TARGETS impact DESTINATION ${CMAKE_INSTALL_PREFIX})
