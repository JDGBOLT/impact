/**
 * @file entity_tilemap.hh
 * @brief Header file for the EntityTilemap class, which contains the
 * properties of the level loaded, with the width, height, and a vector
 * containing integers of all of the tile types, these tiles are used as a
 * lookup table for the various tile types, which is also how the level is
 * stored within the json file.
 * @author Joshua Gwinn (jdgbolt@gmail.com)
 * @version 
 * @date 2012-02-03
 */

#ifndef _ENTITY_TILEMAP_HH_
#define _ENTITY_TILEMAP_HH_

#include "impact.hh"
#include <vector>
class
EntityTilemap
{
 public:
    std::vector<unsigned int> tileMap;
    unsigned int width;
    unsigned int height;
};

#endif
