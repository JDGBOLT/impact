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
 * @file config_base.cc
 * @brief Source file for the ConfigBase class, which is the base class for all
 * configuration parsing classes. It has variables common to all configuration
 * parsers as well as helper functions for common tasks.
 * @author Joshua Gwinn (jdgbolt@gmail.com)
 * @version 
 * @date 2012-03-07
 */

#include "config_base.hh"

const char *
ConfigBase::string_get(json_t *jsonData, std::string key)
{
   if (!jsonData)
     {
        Log_ERR("String parse error: Passed JSON data NULL");
        return "";
     }
   switch (jsonData->type)
     {
      case JSON_OBJECT:
           {
              json_t *jsonString = json_object_get(jsonData, key.c_str());
              if (!jsonString)
                {
                   Log_ERR("String parse error: Key %s not present", key.c_str());
                   return "";
                }
              if (json_is_string(jsonString))
                return json_string_value(jsonString);
              else
                {
                   Log_ERR("String parse error: Key %s not a string", key.c_str());
                   return "";
                }
              break;
           }
      case JSON_ARRAY:
           {
              int index = atoi(key.c_str()); 
              json_t *jsonString = json_array_get(jsonData, index);
              if (!jsonString)
                {
                   Log_ERR("String parse error: Array index %i not present", index);
                   return "";
                }
              if (json_is_string(jsonString))
                return json_string_value(json_array_get(jsonData, index));
              else
                {
                   Log_ERR("String parse error: Array index %i not a string", index);
                   return "";
                }
              break;
           }
      case JSON_STRING:
           {
              return json_string_value(jsonData);
              break;
           }
      default:
           {
              Log_ERR("String parse error: JSON data type not supported");
              return "";
           }
     }
}
