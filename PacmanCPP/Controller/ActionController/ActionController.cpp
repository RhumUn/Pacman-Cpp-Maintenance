#include <iostream>
#include<SDL.h>

#include "ActionController.h"
#include <windows.h>
#include "../../Domain/Pacman/Pacman.h"



using namespace std;


ActionController::ActionController() {}
ActionController::ActionController(Pacman pacman) : pacman(pacman) {}



void ActionController::mouvement(SDL_Event e) {

	if (e.type == SDL_KEYDOWN)
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
	
