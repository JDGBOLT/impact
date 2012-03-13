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
 * @file lz4comp.cc
 * @brief Source file for the lz4comp binary, which, during the build process,
 * will compress the json files used for the game into lz4 compressed files,
 * also can be run directly from the command line to decompress the files
 * directly.
 * @author Joshua Gwinn (jdgbolt@gmail.com)
 * @version 
 * @date 2012-02-14
 */

#include "core/impact_io_lz4.hh"
#include "jansson/jansson.h"
#include "SDL_main.h"

enum
ACTION
{
   COMPRESS=0,
   DECOMPRESS,
   JSON_COMPRESS,
   JSON_DECOMPRESS
};

void
usage_print()
{
   printf("Usage: lz4comp (option) source dest\n");
   printf("Usable Options:\n");
   printf("\t-d decompress\n");
   printf("\t-c compress(default)\n");
   printf("\t-jc compress json file\n");
   printf("\t-jd decompress json file\n");
   printf("\t-h help(this text)\n");
}

int
main(int argc, char *argv[])
{
   ACTION action;
   FILE *in;
   FILE *out;
   Uint32 fileSize;
   char *source = NULL;
   char *dest = NULL;
   char *fileIn = NULL;
   char *fileOut = NULL;

   if (argc < 3 || argc > 4)
     {
        printf("Bad number of arguments:\n");
        usage_print();
        return EXIT_FAILURE;
     }
   if (argv[1][0] == '-' && argc == 4)
     {
        char option = argv[1][1];
        switch (option)
          {
           case 'c': action = COMPRESS; break;
           case 'd': action = DECOMPRESS; break;
           case 'j':
                     {
                        switch (argv[1][2])
                          {
                           case 'c': action = JSON_COMPRESS; break;
                           case 'd': action = JSON_DECOMPRESS; break;
                          }
                        break;
                     }
           case 'h': usage_print(); return EXIT_SUCCESS;
           default:
                     {
                        printf("Invalid Option: %s\n", argv[0]);
                        usage_print();
                        return EXIT_FAILURE;
                     }
          }
        source = argv[2];
        dest = argv[3];
     }
   else
     {
        action = COMPRESS;
        source = argv[1];
        dest = argv[2];
     }              
   in = fopen(source, "rb");
   out = fopen(dest, "wb");
   if (!in)
     {
        Log_CRIT("Could not open source file %s: File not found\n", source);
        return EXIT_FAILURE;
     }
   if (!out)
     {
        Log_CRIT("Could not open destination file %s.\n", dest);
        return EXIT_FAILURE;
     }
   fseek(in, 0, SEEK_END);
   fileSize = ftell(in);
   rewind(in);
   fileIn = (action == JSON_COMPRESS) ? new char[fileSize + 1] : new char[fileSize];
   fread(fileIn, fileSize, 1, in);
   if (!fileIn)
     {
        Log_CRIT("Source file %s is empty.\n", source);
        return EXIT_FAILURE;
     }
   switch (action)
     {
      case COMPRESS: fileOut = ImpactIO::lz4_file_compress(fileIn, &fileSize); break;
      case DECOMPRESS: fileOut = ImpactIO::lz4_file_uncompress(fileIn, &fileSize); break;
      case JSON_COMPRESS:
                       {
                          fileIn[fileSize] = '\0';
                          json_error_t errors;
                          json_t *fileData = json_loads(fileIn, 0, &errors);
                          if (!fileData)
                            {
                               Log_CRIT("Could not parse source file %s: JSON parse error: \n%s", source, errors.text);
                               fclose(in);
                               fclose(out);
                               return EXIT_FAILURE;
                            }
                          char *jsonOut = json_dumps(fileData, (JSON_COMPACT | JSON_SORT_KEYS));
                          if (!jsonOut)
                            {
                               Log_CRIT("Could not encode json data for file %s", source);
                               fclose(in);
                               fclose(out);
                               return EXIT_FAILURE;
                            }
                          json_decref(fileData);
                          fileSize = strlen(jsonOut);
                          fileOut = ImpactIO::lz4_file_compress(jsonOut, &fileSize);
                          delete[] jsonOut;
                          break;
                       }
      case JSON_DECOMPRESS:
                       {
                          char *jsonIn = ImpactIO::lz4_file_uncompress(fileIn, &fileSize);
                          json_error_t errors;
                          jsonIn[fileSize] = '\0';
                          json_t *fileData = json_loads(jsonIn, 0, &errors);
                          if (!fileData)
                            {
                               Log_CRIT("Could not parse source file %s: JSON parse error \n%s", source, errors.text);
                               fclose(in);
                               fclose(out);
                               delete[] jsonIn;
                               return EXIT_FAILURE;
                            }
                          fileOut = json_dumps(fileData, (JSON_INDENT(1) | JSON_SORT_KEYS));
                          json_decref(fileData);
                          fileSize = strlen(fileOut);
                          delete[] jsonIn;
                          break;
                       }
     }
   if (!fileOut)
     {
        Log_CRIT("Could not compress file.\n");
        return EXIT_FAILURE;
     }
   fwrite(fileOut, fileSize, 1, out);
   fclose(in);
   fclose(out);
   return EXIT_SUCCESS;
}
