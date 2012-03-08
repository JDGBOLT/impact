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
 * @file display_state.cc
 * @brief Source file for the DisplayState class, which is the base class for
 * the display module of all states.
 * @author Joshua Gwinn (jdgbolt@gmail.com)
 * @version 
 * @date 2012-01-29
 */

#include "display_state.hh"
#include "SDL/SDL_image.h"

DisplayAsset
DisplayState::image_single_load(std::string imageFilename)
{
   return image_load(imageFilename, false);
}

DisplayAsset
DisplayState::image_multiple_load(std::string imageFilename)
{
   return image_load(imageFilename, true);
}

DisplayAsset
DisplayState::image_load(std::string imageFilename, bool multiple)
{
   // Temporary image surface and optimized image surface
   SDL_Surface *loadedImage = NULL;
   DisplayAsset asset;
   asset.multiple = multiple;

   // Load the image
   loadedImage = IMG_Load(imageFilename.c_str());

   if (loadedImage)
     {
        asset.image[NORMAL] = SDL_DisplayFormat(loadedImage);
        SDL_FreeSurface(loadedImage);

        if (asset.image[NORMAL])
          SDL_SetColorKey(asset.image[NORMAL], colorkeyFLAGS, 
                          SDL_MapRGB(asset.image[NORMAL]->format, colorkeyR, colorkeyG, colorkeyB) );
        else
          {
             Log_ERR("Could not optimize image %s!", imageFilename.c_str());
          }
     }
   else
     {
        Log_ERR("Could not load image %s", imageFilename.c_str());
     }
   asset.width = asset.image[NORMAL]->w;
   asset.height = asset.image[NORMAL]->h;
   if (!multiple) return asset;
   asset.image[MIRRORED] = SDL_CreateRGBSurface(screenFLAGS, asset.image[NORMAL]->w, 
                                                asset.image[NORMAL]->h, 
                                                asset.image[NORMAL]->format->BitsPerPixel,
                                                asset.image[NORMAL]->format->Rmask, 
                                                asset.image[NORMAL]->format->Gmask,
                                                asset.image[NORMAL]->format->Bmask,
                                                asset.image[NORMAL]->format->Amask);
   asset.image[FLIPPED] = SDL_CreateRGBSurface(screenFLAGS, asset.image[NORMAL]->w, 
                                                asset.image[NORMAL]->h, 
                                                asset.image[NORMAL]->format->BitsPerPixel,
                                                asset.image[NORMAL]->format->Rmask, 
                                                asset.image[NORMAL]->format->Gmask,
                                                asset.image[NORMAL]->format->Bmask,
                                                asset.image[NORMAL]->format->Amask);
   asset.image[MIRROR_FLIPPED] = SDL_CreateRGBSurface(screenFLAGS, asset.image[NORMAL]->w, 
                                                      asset.image[NORMAL]->h, 
                                                      asset.image[NORMAL]->format->BitsPerPixel,
                                                      asset.image[NORMAL]->format->Rmask, 
                                                      asset.image[NORMAL]->format->Gmask,
                                                      asset.image[NORMAL]->format->Bmask,
                                                      asset.image[NORMAL]->format->Amask);
   if (SDL_MUSTLOCK(asset.image[NORMAL]))
     SDL_LockSurface(asset.image[NORMAL]);
   Uint32 pixel;
   Uint32 imageWidth = asset.image[NORMAL]->w;
   Uint32 imageHeight = asset.image[NORMAL]->h;
   Uint32 *normalPixels = (Uint32 *) asset.image[NORMAL]->pixels;
   Uint32 *mirroredPixels = (Uint32 *) asset.image[MIRRORED]->pixels;
   Uint32 *flippedPixels = (Uint32 *) asset.image[FLIPPED]->pixels;
   Uint32 *mirrorFlippedPixels = (Uint32 *) asset.image[MIRROR_FLIPPED]->pixels;
   for (int x = 0, reversedX = imageWidth - 1; x < imageWidth; x++, reversedX--)
     {
        for (int y = 0, reversedY = imageHeight - 1; y < imageHeight; y++, reversedY--)
          {
             pixel = normalPixels[ (y * imageWidth) + x];
             mirroredPixels[ (y * imageWidth) + reversedX] = pixel;
             flippedPixels[ (reversedY * imageWidth) + x] = pixel;
             mirrorFlippedPixels[ (reversedY * imageWidth) + reversedX] = pixel;
          }
     }
   if (SDL_MUSTLOCK(asset.image[NORMAL]))
     SDL_UnlockSurface(asset.image[NORMAL]);
   if (asset.image[NORMAL]->flags & SDL_SRCCOLORKEY)
     {
        SDL_SetColorKey(asset.image[MIRRORED], colorkeyFLAGS, 
                        SDL_MapRGB(asset.image[MIRRORED]->format, 
                                   colorkeyR, colorkeyG, colorkeyB) );
        SDL_SetColorKey(asset.image[FLIPPED], colorkeyFLAGS, 
                        SDL_MapRGB(asset.image[FLIPPED]->format, 
                                   colorkeyR, colorkeyG, colorkeyB) );
        SDL_SetColorKey(asset.image[MIRROR_FLIPPED], colorkeyFLAGS, 
                        SDL_MapRGB(asset.image[MIRROR_FLIPPED]->format, 
                                   colorkeyR, colorkeyG, colorkeyB) );
     }
   return asset;
}

ErrorReturn
DisplayState::surface_apply(int x, int y, SDL_Surface *source,
                            SDL_Surface *destination, SDL_Rect *clip)
{
   SDL_Rect offset;
   offset.x = x;
   offset.y = y;
   SDL_BlitSurface(source, clip, destination, &offset);
   return RETURN_NORMAL;
}
