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

#ifndef _LOADER_HH_
#define _LOADER_HH_

/**
 * @file loader.hh
 * @brief Header file for the ImpactLoader class, which handles loading of
 * textual game data and parsing it, returning it in usable form for the core
 * module to handle.
 * @author Joshua Gwinn (jdgbolt@gmail.com)
 * @version 
 * @date 2012-02-03
 */

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
