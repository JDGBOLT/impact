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

/**
 * @file config_global.cc
 * @brief Source file for the ConfigGlobal class, which handles loading the
 * global configuration file contained within the root of the data directory,
 * which has various settings such as directory paths and other settings common
 * to the game itself.
 * @author Joshua Gwinn (jdgbolt@gmail.com)
 * @version 
 * @date 2012-02-14
 */

#include "config_global.hh"

ErrorReturn
ConfigGlobal::global_config_load()
{
   json_t *jsonData = ImpactIO::conf_load("config");
   if (!jsonData)
     {
        Log_ERR("Could not open global configuration config.json!");
        return RETURN_ERROR;
     }
   assetsDirectory = string_get(jsonData, "AssetsDirectory");
   chaptersDirectory = string_get(jsonData, "ChaptersDirectory"); 
   defaultGame = string_get(jsonData, "DefaultGame");
   gamesDirectory = string_get(jsonData, "GamesDirectory");
   imagesDirectory = string_get(jsonData, "ImagesDirectory");
   musicDirectory = string_get(jsonData, "MusicDirectory");
   soundsDirectory = string_get(jsonData, "SoundsDirectory");
   tilesetsDirectory = string_get(jsonData, "TilesetsDirectory");
   json_decref(jsonData);
   return RETURN_NORMAL;
}

ErrorReturn
ConfigGlobal::global_config_write()
{
   json_error_t jsonErrors;
   json_t *jsonData = json_pack_ex(&jsonErrors, 0, "{s:s,s:s,s:s,s:s,s:s,s:s,s:s}",
                                   "AssetsDirectory", assetsDirectory.c_str(),
                                   "ChaptersDirectory", chaptersDirectory.c_str(),
                                   "DefaultGame", defaultGame.c_str(),
                                   "GamesDirectory", gamesDirectory.c_str(),
                                   "ImagesDirectory", imagesDirectory.c_str(),
                                   "MusicDirectory", musicDirectory.c_str(),
                                   "SoundsDirectory", soundsDirectory.c_str(),
                                   "TilesetsDirectory", tilesetsDirectory.c_str()
                                  );
   if (!jsonData)
     {
        Log_ERR("Could not pack global configuration config.json:\n%s", jsonErrors.text);
        return RETURN_ERROR;
     }
   if (ImpactIO::conf_write("config", jsonData, "json") != RETURN_NORMAL)
     {
        Log_ERR("Could not write global configuration data config.json!");
        json_decref(jsonData);
        return RETURN_ERROR;
     }
   json_decref(jsonData);
   return RETURN_NORMAL;
}
