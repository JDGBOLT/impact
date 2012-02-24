/* vim:ts=8 sw=3 sts=3 expandtab cino=>5n-3f0^-2{2(0W1st0:
 * 
 * Copyright (C) 
 * 2012 - Joshua Gwinn (jdgbolt@gmail.com)
 * This program is free software; you can redistribute it and/or
 * modify it under the terms of the GNU General Public License
 * as published by the Free Software Foundation; either version 2
 * of the License, or (at your option) any later version.
 * 
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * included GNU General Public License file located in COPYING or at
 * http://www.gnu.org/licenses/gpl-2.0.html for more details.
 */

#ifndef _TILE_MAP_HH_
#define _TILE_MAP_HH_

/**
 * @file tile_map.hh
 * @brief Header file for the TileMap struct, which is a data storage struct
 * which stores the tile map for the currently loaded level, as well as
 * additional information such as the width and height of the map and tiles,
 * and also whether the level is to be parsed in a vertical configuration,
 * which essentially means the difference of the level data sectioned off into
 * rows or columns.
 * @author Joshua Gwinn (jdgbolt@gmail.com)
 * @version 
 * @date 2012-02-23
 */

#include "impact.hh"
#include "util/tile_type.hh"
#include <vector>

struct
TileMap
{
   std::vector<TileType> tileMap;
   unsigned int width;
   unsigned int height;
   unsigned short tileWidth;
   unsigned short tileHeight;
   bool vertical;
};

#endif
