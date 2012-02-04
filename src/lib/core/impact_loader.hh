/**
 * @file loader.hh
 * @brief Header file for the ImpactLoader class, which handles loading of
 * textual game data and parsing it, returning it in usable form for the core
 * module to handle.
 * @author Joshua Gwinn (jdgbolt@gmail.com)
 * @version 
 * @date 2012-02-03
 */

#ifndef _LOADER_HH_
#define _LOADER_HH_

#include "impact.hh"
#include "jansson/jansson.h"
#include "core/entity_tilemap.hh"
#include <string>

class
ImpactLoader
{
 public:
    ErrorReturn
       config_parse(std::string fileName);
    ErrorReturn
       chapter_load(int chapterNumber);
    ErrorReturn
       level_load(EntityTilemap *tileData, std::string level);
 private:
    // Functions
    json_t *
       file_load(std::string fileName);
    // Variables
    json_t *config;
    json_t *chapters;
    json_t *tilesets;
    json_t *loadedChapter;
    json_t *loadedTileset;
};

#endif
