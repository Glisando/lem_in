#ifndef MAP_HPP
#define MAP_HPP

#include "MyFramework.hpp"
#include "TextureManager.hpp"

class Map {

    public:
        Map();
        ~Map();
        void LoadMap(int arr[20][25]);
        void DrawMap();
        void init_map(int arr[20][25]);

    private:
        SDL_Rect src, dst;

        SDL_Texture *grass;
        SDL_Texture *water;
        int map[20][25];
};

#endif