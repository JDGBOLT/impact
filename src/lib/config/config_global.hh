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

#ifndef _CONFIG_GLOBAL_HH_
#define _CONFIG_GLOBAL_HH_

/**
 * @file config_global.hh
 * @brief Header file for the ConfigGlobal class, which handles loading the
 * global configuration file contained within the root of the data directory,
 * which has various settings such as directory paths and other settings common
 * for the game itself.
 * @author Joshua Gwinn (jdgbolt@gmail.com)
 * @version 
 * @date 2012-02-14
 */

#include "impact.hh"
#include "core/impact_io.hh"

class
ConfigGlobal
{
 public:
    // Functions
    ErrorReturn
       global_config_load();
    ErrorReturn
       global_config_write();
    // Variables
    std::string chaptersDirectory;
    std::string imagesDirectory;
    std::string musicDirectory;
    std::string soundsDirectory;
    std::string tilesetsDirectory;
 private:
};

#endif
