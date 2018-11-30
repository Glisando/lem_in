#ifndef MYFRAMEWORK_HPP
# define MYFRAMEWORK_HPP

#include <iostream>

#include "Framework.h"
#include "TextureManager.hpp"
#include "GameObject.hpp"
#include "Map.hpp"

/* Test Framework realization */
class MyFramework : public Framework {

	public:
		bool isRunning;
		int count = 0;

		MyFramework();
		MyFramework(MyFramework const &ref);
		~MyFramework();

		MyFramework &operator=(MyFramework const &ref);

		virtual void PreInit(int& width, int& height, bool& fullscreen);
		virtual bool Init();
		virtual void Close();
		virtual bool Tick();
		virtual void onMouseMove(int x, int y, int xrelative, int yrelative);
		virtual void onMouseButtonClick(FRMouseButton button, bool isReleased);
		virtual void onKeyPressed(FRKey k);
		virtual void onKeyReleased(FRKey k);

		virtual void handleEvents();
		virtual void update();
		virtual void render();
		virtual bool running();
};

#endif