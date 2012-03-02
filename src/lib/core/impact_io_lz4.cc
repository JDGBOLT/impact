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
 * @file impact_io.cc
 * @brief Source file for the ImpactIO namespace, which is a namespace
 * containing functions to handle all textual data within the game of Impact.
 * This file contains the base functions for the handling of compressing and
 * uncompressing of lz4 compressed files.
 * @author Joshua Gwinn (jdgbolt@gmail.com)
 * @version 
 * @date 2012-02-13
 */

#include "impact_io_lz4.hh"

char *
ImpactIO::lz4_file_compress(char *fileString, Uint32 *length)
{
   // Prepare to compress the file, creating a character array 10% larger than
   // the length of the string passed in
   char *tempFileData = new char[LZ4_compressBound(*length)];
   // Compress the file, and check to ensure it compressed correctly
   int compressedLength = LZ4_compress(fileString, tempFileData, *length);
   if (compressedLength < 0)
     {
        delete[] tempFileData;
        Log_ERR("Could not compress lz4 data, number of bytes compressed was %i", compressedLength);
        return NULL;
     }
   // Create a new character array that is exactly the size of the compressed
   // data plus the metadata, which consists of a magic number, and the
   // uncompressed file size, in bytes, and setting these
   char *fileData = new char[compressedLength + (2 * sizeof(Uint32))];
   Uint32 *tempData = (Uint32 *)fileData;
   tempData[0] = ARCHIVE_MAGICNUMBER;
   tempData[1] = *length;
   tempData = NULL;
   // Copy the rest of the compressed data into the character array, and
   // returning the length of the compressed data via the length variable
   // passed in
   memcpy((fileData + (2 * sizeof(Uint32))), tempFileData, compressedLength);
   *length = compressedLength + (2 * sizeof(Uint32));
   delete[] tempFileData;
   return fileData;
}

char *
ImpactIO::lz4_file_uncompress(char *fileData, Uint32 *length)
{
   // Read in the metadata from the file data passed in, taking in the
   // uncompressed size and the magic number, and checking it to ensure it is
   // the correct kind of file
   Uint32 *tempFileData = (Uint32 *) fileData;
   Uint32 magicNumber = tempFileData[0];
   Uint32 uncompressedLength = tempFileData[1];
   tempFileData = NULL;
   if (magicNumber != ARCHIVE_MAGICNUMBER)
     {
        Log_ERR("Data passed is not compressed LZ4 format!");
        return NULL;
     }
   // Allocate memory for the uncompressed data, with an additional byte for
   // the \0 character, if necessary, then uncompress it and return it, along
   // with the length of the uncompressed data
   char *fileString = new char[uncompressedLength + 1];
   Uint32 newUncompressedLength = LZ4_uncompress(
      (fileData + (sizeof(Uint32) * 2)), fileString, uncompressedLength);
   *length = uncompressedLength;
   return fileString;
}
