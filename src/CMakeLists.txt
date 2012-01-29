# @file /src/CMakeLists.txt
# @brief CMake file for the src dirctory
# @author Joshua Gwinn (jdgbolt@gmail.com)
# @date 2012-01-28

# Set placeholder variable to pass to the /src/bin/CMakeLists.txt file
SET(LIB_SOURCES)

# Set include directories
INCLUDE_DIRECTORIES(
   "${CMAKE_CURRENT_SOURCE_DIR}/lib"
   "${CMAKE_CURRENT_SOURCE_DIR}/lib/include"
)

# Include subdirectories in the tree for build process
ADD_SUBDIRECTORY(lib)
ADD_SUBDIRECTORY(bin)
