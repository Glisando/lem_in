#include "TextureManager.hpp"

SDL_Texture *TextureManager::LoadTexture(const char *filename)
{
    SDL_Surface *Surfacetmp = IMG_Load(filename);
    SDL_Texture *tex = SDL_CreateTextureFromSurface(MyFramework::renderer, Surfacetmp);
    SDL_FreeSurface(Surfacetmp);

    return (tex);
}

void TextureManager::Draw(SDL_Texture *tex, SDL_Rect src, SDL_Rect dst)
{
    SDL_RenderCopy(MyFramework::renderer, tex, &src, &dst);
}
