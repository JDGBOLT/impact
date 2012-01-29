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
