#include <iostream>
#include<SDL.h>

#include "ActionController.h"
#include <windows.h>
#include "Pacman.h"


using namespace std;


ActionController::ActionController() {}
ActionController::ActionController(Pacman pacman) : pacman(pacman) {}



void ActionController::mouvement() {

	while (!quit)
	{
		while (SDL_PollEvent(&e) != 0)

			if (e.type == SDL_QUIT)
			{
				quit = true;
			}

			else if (e.type == SDL_KEYDOWN)
			{
				switch (e.key.keysym.sym)
				{
				case SDLK_UP: pacman.goUp();
					break;

				case SDLK_DOWN: pacman.goDown();
					break;

				case SDLK_LEFT: pacman.goLeft();
					break;

				case SDLK_RIGHT: pacman.goRight();
					break;

				default:
					break;
				}
			}
	}
}
