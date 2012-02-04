/**
 * @file loader.cc
 * @brief Source file for the ImpactLoader class, which handles loading of
 * textual game data and parsing it, returning it in usable form for the core
 * module to handle.
 * @author Joshua Gwinn (jdgbolt@gmail.com)
 * @version 
 * @date 2012-02-03
 */

#include "impact_loader.hh"

json_t *
ImpactLoader::file_load(std::string fileName)
{
   fileName = dataDIR + fileName;
   json_error_t error;
   json_t *file = json_load_file(fileName.c_str(), 0, &error);
   if (!file)
     {
        Log_ERR("Could not load %s:\n%s", fileName.c_str(), error.text);
        return NULL;
     }
   else
     {
        return file;
     }
}
ErrorReturn
ImpactLoader::config_parse(std::string fileName)
{
   config = file_load(fileName);
   if (config)
     {
        fileName = json_string_value(json_object_get(config, "ChapterList"));
        chapters = file_load(fileName);
        fileName = json_string_value(json_object_get(config, "TilesetList"));
        tilesets = file_load(fileName);
        return RETURN_NORMAL;
     }
   else
     {
        Log_ERR("Could not load config file!");
        return RETURN_ERROR;
     }
}
ErrorReturn
ImpactLoader::level_load(EntityTilemap *tileData, std::string level)
{
   json_t *loadedLevel = NULL;
   if (loadedChapter)
     {
        loadedLevel = json_object_get(json_object_get(loadedChapter, "Levels"), level.c_str());
        if (loadedLevel)
          {
             (*tileData).height = json_integer_value(json_object_get(loadedLevel, "Height"));
             (*tileData).width = json_integer_value(json_object_get(loadedLevel, "Width"));
             (*tileData).tileMap.reserve((*tileData).height * (*tileData).width);
             json_t *tilemapArray = json_object_get(loadedLevel, "Tilemap");
             if (tilemapArray && json_is_array(tilemapArray))
               {
                  for (int i = 0; i < json_array_size(tilemapArray); i++)
                    {
                       (*tileData).tileMap.push_back(json_integer_value(json_array_get(tilemapArray, i)));
                    }
               }
             else
               {
                  Log_WARN("Level data TileMap from level %s is not an array.", level.c_str());
                  return RETURN_ERROR;
               }
          }
        else
          {
             Log_ERR("Could not load level %s!", level.c_str());
             return RETURN_ERROR;
          }
     }
   else
     {
        Log_WARN("No loaded chapter.");
        return RETURN_ERROR;
     }
   return RETURN_NORMAL;
}

ErrorReturn
ImpactLoader::chapter_load(int chapterNumber)
{
   if (json_array_size(chapters) < chapterNumber)
     {
        Log_ERR("Chapter number %i is greater than the number of chapters available!", chapterNumber);
        return RETURN_ERROR;
     }
   std::string fileName = json_string_value(json_array_get(chapters, chapterNumber - 1));
   loadedChapter = file_load(fileName);
   if (loadedChapter)
     {
        Log_DBG("Loaded chapter number %i, %s.", chapterNumber, fileName.c_str());
        return RETURN_NORMAL;
     }
   else
     {
        Log_ERR("Could not open chapter number %i, %s!", chapterNumber, fileName.c_str());
        return RETURN_ERROR;
     }
}
