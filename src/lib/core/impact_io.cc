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
 * @file impact_io.cc
 * @brief Source file for the ImpactIO namespace, which is a namespace
 * containing functions to handle all textual data within the game of Impact.
 * It also contains the base functions for the handling of compressing and
 * uncompressing of lz4 compressed files.
 * @author Joshua Gwinn (jdgbolt@gmail.com)
 * @version 
 * @date 2012-02-13
 */

#include "impact_io.hh"

json_t *
ImpactIO::conf_load(std::string fileName)
{
   // Attempt to open json file first, if it can, it loads it and parses it
   std::string tempFileName = dataDIR + fileName + ".json";
   std::fstream file(tempFileName.c_str(), (std::ios::in | std::ios::ate));
   if (file.good())
     {
        // Read in the file
        Uint32 fileSize = file.tellg();
        char *fileString = new char[fileSize + 1];
        file.seekg(0);
        file.read(fileString, fileSize);
        file.close();
        // Append \0 to the end of the file string, to make it a character
        // array, then parse it, returning the json object
        fileString[fileSize] = '\0';
        json_t *fileData = json_parse(fileString, &tempFileName);
        delete[] fileString;
        return fileData;
     }
   else
     {
        // Attempt to open .lz4 file next
        tempFileName = dataDIR + fileName + ".lz4";
        file.open(tempFileName.c_str(), (std::ios::in | std::ios::binary | std::ios::ate));
        if (!file.good())
          {
             file.close();
             Log_ERR("Could not open file %s: File not found!", tempFileName.c_str());
             return NULL;
          }
        Uint32 fileSize = file.tellg();
        char *fileData = new char[fileSize];
        // Read .lz4 file in, then pass it to the uncompress function
        file.seekg(0);
        file.read(fileData, fileSize);
        file.close();
        char *fileString = lz4_file_uncompress(fileData, &fileSize);
        // Append \0 to the end of the file string, to make it a character
        // array, then parse it, returning the json object
        fileString[fileSize] = '\0';
        json_t *jsonData = json_parse(fileString, &tempFileName);
        delete[] fileString;
        delete[] fileData;
        return jsonData;
     }
   file.close();
   return NULL;
}

ErrorReturn
ImpactIO::conf_write(std::string fileName, json_t *fileData, std::string type)
{
   std::fstream file;
   std::string tempFileName;
   // Check whether we are writing a .json file, or a compressed .lz4 file
   if (type == "json")
     {
        // Attempt to open file for writing
        tempFileName = dataDIR + fileName + ".json";
        file.open(tempFileName.c_str(), (std::ios::out | std::ios::trunc));
        if (!file.good())
          {
             Log_ERR("Could not open file %s!", tempFileName.c_str());
             return RETURN_ERROR;
          }
        // Create json text out of the json object passed in, having minimal
        // indentation to reduce filesize, and sorting the keys
        char *jsonString = json_dumps(fileData, (JSON_INDENT(1) | JSON_SORT_KEYS));
        if (!jsonString)
          {
             Log_ERR("Could not encode json data!");
             return RETURN_ERROR;
          }
        // Write the json text to the file, then close it
        file.write(jsonString, strlen(jsonString));
        file.close();
        delete[] jsonString;
        return RETURN_NORMAL;
     }
   else if (type == "lz4")
     {
        // Attempt to open file for writing
        tempFileName = dataDIR + fileName + ".lz4";
        file.open(tempFileName.c_str(), (std::ios::out | std::ios::binary | std::ios::trunc));
        if (!file.good())
          {
             Log_ERR("Could not open file %s!", fileName.c_str());
             return RETURN_ERROR;
          }
        // Create json text out of the json object passed in, passing it the
        // options to make it compact, to reduce filesize even further, and
        // sorting the keys
        char *jsonString = json_dumps(fileData, (JSON_COMPACT | JSON_SORT_KEYS));
        if (!jsonString)
          {
             Log_ERR("Could not encode json data!");
             file.close();
             return RETURN_ERROR;
          }
        // Take the length of the string, and pass it along with the json text
        // to the compress function
        Uint32 fileSize = strlen(jsonString);
        char *fileData = lz4_file_compress(jsonString, &fileSize);
        // Check to ensure that the file was compressed and passed back
        if (!fileData)
          {
             Log_ERR("Could not compress lz4 configuration file %s!", tempFileName.c_str());
             delete[] jsonString;
             file.close();
             return RETURN_ERROR;
          }
        // Write data to file, then close it and return
        file.write(fileData, fileSize);
        file.close();
        delete[] jsonString;
        delete[] fileData;
        return RETURN_NORMAL;
     }
   else
     {
        // Unsupported output type
        Log_ERR("Type specified %s: Not supported!", type.c_str());
        return RETURN_ERROR;
     }
}

json_t *
ImpactIO::json_parse(char *fileString, std::string *fileName)
{
   // Create pointers for json and error objects, then load the json text
   // passed in
   json_t *loaded;
   json_error_t loadedErrors;
   if (!strlen(fileString))
     return NULL;
   loaded = json_loads(fileString, 0, &loadedErrors);
   // Check to see if it loaded correctly, and if so, return it
   if (!loaded)
     {
        Log_ERR("Could not load file %s: %s", fileName->c_str(), loadedErrors.text);
        return NULL;
     }
   return loaded;
}

char *
ImpactIO::lz4_file_compress(char *fileString, Uint32 *length)
{
   // Prepare to compress the file, creating a character array 10% larger than
   // the length of the string passed in
   char *tempFileData = new char[*length + (*length / 10)];
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
