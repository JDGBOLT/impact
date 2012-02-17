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
 * @file impact_io.hh
 * @brief Header file for the ImpactIO namespace, which is a namespace
 * containing functions to handle all textual data within the game of Impact.
 * @author Joshua Gwinn (jdgbolt@gmail.com)
 * @version 
 * @date 2012-02-13
 */

#ifndef _IMPACT_IO_HH_
#define _IMPACT_IO_HH_

#include "impact.hh"
#include "core/impact_io_lz4.hh"
#include "lz4/lz4.h"
#include "jansson/jansson.h"
#include <string>
#include <fstream>

namespace
ImpactIO
{
   json_t *
      conf_load(std::string fileName);
   ErrorReturn
      conf_write(std::string fileName, json_t *fileData, std::string type);
   json_t *
      json_parse(char *fileString, std::string *fileName);
}

#endif