/* Copyright (C) 
 * 2012 - Joshua Gwinn (jdgbolt@gmail.com)
 * This program is free software; you can redistribute it and/or
 * modify it under the terms of the GNU General Public License
 * as published by the Free Software Foundation; either version 2
 * of the License, or (at your option) any later version.
 * 
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 * 
 * You should have received a copy of the GNU General Public License
 * along with this program; if not, write to the Free Software
 * Foundation, Inc., 59 Temple Place - Suite 330, Boston, MA  02111-1307, USA.
 * 
 */


#ifndef _ENTITY_TILEMAP_HH_
#define _ENTITY_TILEMAP_HH_

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
