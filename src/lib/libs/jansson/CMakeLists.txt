# @file CMakeLists.txt
# @brief CMake file for the /src/lib/libs/jansson directory
# @author Joshua Gwinn (jdgbolt@gmail.com)
# @version 
# @date 2012-02-02

# Set variable to add files to build process
SET(CURDIR ${CMAKE_CURRENT_SOURCE_DIR})
SET(JANSSON_SOURCES
   "${CURDIR}/dump.c"
   "${CURDIR}/error.c"
   "${CURDIR}/hashtable.c"
   "${CURDIR}/load.c"
   "${CURDIR}/memory.c"
   "${CURDIR}/pack_unpack.c"
   "${CURDIR}/strbuffer.c"
   "${CURDIR}/strconv.c"
   "${CURDIR}/utf.c"
   "${CURDIR}/value.c"
   PARENT_SCOPE)


