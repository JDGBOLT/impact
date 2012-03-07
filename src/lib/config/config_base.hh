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

#ifndef _CONFIG_BASE_HH_
#define _CONFIG_BASE_HH_

/**
 * @file config_base.hh
 * @brief Header file for the ConfigBase class, which is the base class for all
 * configuration parsing classes. It has variables common to all configuration
 * parsers as well as helper functions for common tasks.
 * @author Joshua Gwinn (jdgbolt@gmail.com)
 * @version 
 * @date 2012-03-07
 */

#include "impact.hh"
#include "core/impact_io.hh"

class
ConfigBase
{
 protected:
    const char *
       string_get(json_t *jsonData, std::string key = "");
};
#endif
