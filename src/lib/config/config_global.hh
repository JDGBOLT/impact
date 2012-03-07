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
#include "config/config_base.hh"
#include "core/impact_io.hh"

class
ConfigGlobal : public ConfigBase
{
 public:
    // Functions
    ErrorReturn
       global_config_load();
    ErrorReturn
       global_config_write();
    // Variables
    std::string assetsDirectory;
    std::string chaptersDirectory;
    std::string gamesDirectory;
    std::string imagesDirectory;
    std::string musicDirectory;
    std::string soundsDirectory;
    std::string tilesetsDirectory;
 private:
};

#endif
