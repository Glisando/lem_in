#ifndef TEXTUREMANAGER_HPP
# define TEXTUREMANAGER_HPP

#include "MyFramework.hpp"

class TextureManager {

    public:
        static SDL_Texture *LoadTexture(const char *filename);
        static void Draw(SDL_Texture *tex, SDL_Rect src, SDL_Rect dst);
};

#endif