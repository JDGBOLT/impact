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

enum
ACTION
{
   COMPRESS=0,
   DECOMPRESS,
};

void
usage_print()
{
   printf("Usage: lz4comp (option) source dest\n");
   printf("Usable Options:\n");
   printf("\t-d decompress\n");
   printf("\t-c compress(default)\n");
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
        printf("Could not open source file %s: File not found\n", source);
        return EXIT_FAILURE;
     }
   if (!out)
     {
        printf("Could not open destination file %s.\n", dest);
        return EXIT_FAILURE;
     }
   fseek(in, 0, SEEK_END);
   fileSize = ftell(in);
   rewind(in);
   fileIn = new char[fileSize];
   fread(fileIn, fileSize, 1, in);
   if (!fileIn)
     {
        printf("Source file %s is empty.\n", source);
        return EXIT_FAILURE;
     }
   fileOut = (action == COMPRESS) ? ImpactIO::lz4_file_compress(fileIn, &fileSize) :
                                    ImpactIO::lz4_file_uncompress(fileIn, &fileSize);
   if (!fileOut)
     {
        printf("Could not compress file.\n");
        return EXIT_FAILURE;
     }
   fwrite(fileOut, fileSize, 1, out);
   fclose(in);
   fclose(out);
   return EXIT_SUCCESS;
}
