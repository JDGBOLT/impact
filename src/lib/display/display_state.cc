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

SDL_Surface *
DisplayState::image_load(std::string imageFilename)
{
   // Temporary image surface and optimized image surface
   SDL_Surface *loadedImage = NULL;
   SDL_Surface *optimizedImage = NULL;

   // Load the image
   loadedImage = IMG_Load(imageFilename.c_str());

   if (!loadedImage)
     {
        optimizedImage = SDL_DisplayFormat(loadedImage);
        SDL_FreeSurface(loadedImage);

        if (!optimizedImage)
          SDL_SetColorKey(optimizedImage, colorkeyFLAGS, 
                          SDL_MapRGB(optimizedImage->format, colorkeyR, colorkeyG, colorkeyB) );
     }
   return optimizedImage;
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