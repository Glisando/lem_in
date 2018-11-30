#include "Framework.h"
#include "MyFramework.hpp"

SDL_Renderer *Framework::renderer = nullptr;
GameObject *player;
GameObject *enemy;
Map *map;

MyFramework::MyFramework(){}
MyFramework::MyFramework(MyFramework const &ref){ *this = ref; }
MyFramework::~MyFramework(){}

MyFramework &MyFramework::operator=(MyFramework const &ref){
    this->window = ref.window;
    this->renderer = ref.renderer;
    return *this;
}

bool MyFramework::running() { return isRunning;}


void MyFramework::PreInit(int& width, int& height, bool& fullscreen)
{
	SDL_Init(SDL_INIT_VIDEO);

	int flags = 0;
	isRunning = false;
	if (fullscreen)
		flags = SDL_WINDOW_FULLSCREEN;
	if (SDL_Init(SDL_INIT_EVERYTHING) == 0)
	{
		std::cout << "Subsystems initialised ..." << std::endl;
		window = SDL_CreateWindow("Crimsonland", SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, width, height, flags);
	}
	renderer = SDL_CreateRenderer(window, -1, 0);
	if (MyFramework::Init())
	{
		isRunning = true;
		std::cout << "Window and renderer created ..." << std::endl;
		SDL_SetRenderDrawColor(renderer, 255, 255, 255, 255);
	}
	player = new GameObject("data/soldier.png", 0, 0);
	enemy = new GameObject("data/zombie.png", 50, 50);
	map = new Map();
}

bool MyFramework::Init() {
	if (!window || !renderer)
		return (false);
	return(true);
}

void MyFramework::handleEvents()
{
	SDL_Event event;
	SDL_PollEvent(&event);

	switch (event.type)
	{
		case SDL_QUIT:
			isRunning = false;
			break ;
		default:
			break ;
	}
}

void MyFramework::render()
{
	SDL_RenderClear(renderer);
	// this is where we would add stuf to render
	map->DrawMap();
	player->render();
	enemy->render();
	SDL_RenderPresent(renderer);

}

void MyFramework::Close() {
	SDL_DestroyWindow(window);
	SDL_DestroyRenderer(renderer);
	SDL_Quit();
	std::cout << "Game cleaned" << std::endl;
}

void MyFramework::update(){
	player->update();
	enemy->update();
}

bool MyFramework::Tick() {
    // drawTestBackground();
    return false;
}

void MyFramework::onMouseMove(int x, int y, int xrelative, int yrelative) {

}

void MyFramework::onMouseButtonClick(FRMouseButton button, bool isReleased) {

}

void MyFramework::onKeyPressed(FRKey k) {
}

void MyFramework::onKeyReleased(FRKey k) {
}