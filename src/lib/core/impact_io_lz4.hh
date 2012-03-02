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

#ifndef _IMPACT_IO_LZ4_HH_
#define _IMPACT_IO_LZ4_HH_

/**
 * @file impact_io.hh
 * @brief Header file for the ImpactIO namespace, which is a namespace
 * containing functions to handle all textual data within the game of Impact.
 * This file contains the base functions for handling of compressing and
 * uncompressing lz4 compressed files.
 * @author Joshua Gwinn (jdgbolt@gmail.com)
 * @version 
 * @date 2012-02-13
 */

#include "impact.hh"
#include "lz4/lz4.h"
#include <string>

// Defines for the archive format
#define ARCHIVE_MAGICNUMBER 0x184C2102
#define ARCHIVE_MAGICNUMBER_SIZE 4
#define ARCHIVE_MAGICNUMBER_OFFSET 8

namespace
ImpactIO
{
   char *
      lz4_file_compress(char *fileString, Uint32 *length);
   char *
      lz4_file_uncompress(char *fileData, Uint32 *length);
}

#endif
