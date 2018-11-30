#include "GameObject.hpp"

GameObject::GameObject(const char *texturesheet, int x, int y)
{
    objTex = TextureManager::LoadTexture(texturesheet);
    xpos = x;
    ypos = y;
}

void GameObject::update()
{
    xpos++;
    ypos++;

    srcRect.h = 32 * 3;
    srcRect.w = 32 * 3;
    srcRect.x = 0;
    srcRect.y = 0;

    dstRect.x = xpos;
    dstRect.y = ypos;
    dstRect.w = srcRect.w / 3;
    dstRect.h = srcRect.h / 2;
}

void GameObject::render()
{
    SDL_RenderCopy(MyFramework::renderer, objTex, &srcRect, &dstRect);

}