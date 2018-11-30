#include "Map.hpp"

int lvl1[20][25];

Map::Map() {
    grass = TextureManager::LoadTexture("data/frame.png");
    init_map(lvl1);
    LoadMap(lvl1);
    src.x = src.y = 0;
    src.h = 32 * 2;
    src.w = 32 * 2;

    dst.x = dst.y = 0;
}

void Map::LoadMap(int arr[20][25])
{
    for (int i = 0; i < 20; i++)
    {
        for (int j = 0; j < 25; j++)
            map[i][j] = arr[i][j];
    }
}

void Map::DrawMap()
{
    int type = 0;

    for (int i = 0; i < 20; i++)
    {
        for (int j = 0; j < 25; j++)
        {
            type = map[i][j];
            
            dst.h = 32;
            dst.w = 32;

            dst.x = j * 32;
            dst.y = i * 32;

            switch (type) {
                case 0:
                    TextureManager::Draw(grass, src, dst);
                    break ;
                default:
                    break ;
            }
        }
    }
}

void Map::init_map(int arr[20][25])
{
    for (int i = 0; i < 20; i++)
    {
        for (int j = 0; j < 25; j++)
            arr[i][j] = 0;
    }
}