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

const char *confFormat = "{s:s,\
                           s:s,\
                           s:s,\
                           s:s,\
                           s:s}";
enum 
GlobalConfigPaths
{
   CHAPTERS_DIRECTORY = 0,
   IMAGES_DIRECTORY,
   MUSIC_DIRECTORY,
   SOUNDS_DIRECTORY,
   TILESETS_DIRECTORY,
   NUM_PATHS
};

ErrorReturn
ConfigGlobal::global_config_load()
{
   char *paths[NUM_PATHS];
   json_error_t jsonErrors;
   json_t *jsonData = ImpactIO::conf_load("config");
   if (!jsonData)
     {
        Log_ERR("Could not open global configuration config.json!");
        return RETURN_ERROR;
     }
   if (json_unpack_ex(jsonData, &jsonErrors, JSON_STRICT, confFormat,
                   "ChaptersDirectory", &paths[CHAPTERS_DIRECTORY],
                   "ImagesDirectory", &paths[IMAGES_DIRECTORY],
                   "MusicDirectory", &paths[MUSIC_DIRECTORY],
                   "SoundsDirectory", &paths[SOUNDS_DIRECTORY],
                   "TilesetsDirectory", &paths[TILESETS_DIRECTORY]
                  ) < 0)
     {
        Log_ERR("Could not unpack global config file config.json:\n%s", jsonErrors.text);
        json_decref(jsonData);
        return RETURN_ERROR;
     }
   chaptersDirectory = paths[CHAPTERS_DIRECTORY];
   imagesDirectory = paths[IMAGES_DIRECTORY];
   musicDirectory = paths[MUSIC_DIRECTORY];
   soundsDirectory = paths[SOUNDS_DIRECTORY];
   tilesetsDirectory = paths[TILESETS_DIRECTORY];
   json_decref(jsonData);
   return RETURN_NORMAL;
}

ErrorReturn
ConfigGlobal::global_config_write()
{
   json_error_t jsonErrors;
   json_t *jsonData = json_pack_ex(&jsonErrors, 0, confFormat,
                                   "ChaptersDirectory", chaptersDirectory.c_str(),
                                   "ImagesDirectory", imagesDirectory.c_str(),
                                   "MusicDirectory", musicDirectory.c_str(),
                                   "SoundsDirectory", soundsDirectory.c_str(),
                                   "TilesetsDirectory", tilesetsDirectory.c_str()
                                  );
   if (!jsonData)
     {
        Log_ERR("Could not pack global configuration config.json:\n%s", jsonErrors.text);
        json_decref(jsonData);
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
