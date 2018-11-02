#include <iostream>
#include <SDL.h>
#include <SDL_image.h>
#include <stdio.h>
#include <string>
#include <windows.h>

#include "WindowController.h"
#include "../../Domain/Pacman/Pacman.h"

using namespace std;

	WindowController :: WindowController(){}

	void WindowController::create(Pacman petitPacman){

		initWindow();
	
		bool quit = false;


			
		while (!quit)
		{
			loadImage(petitPacman);
			SDL_BlitSurface(image, NULL, screenSurface, NULL);
			SDL_UpdateWindowSurface(window);

			while (SDL_PollEvent(&e) != 0)
			{
				if (e.type == SDL_QUIT)
				{
					quit = true;
				}
			}

			if (e.type == SDL_KEYDOWN)
			{
				switch(e.key.keysym.sym)
				{
				case SDLK_UP: petitPacman.goUp();
					break;

				case SDLK_DOWN: petitPacman.goDown();
					break;

				case SDLK_LEFT: petitPacman.goLeft();
					break;

				case SDLK_RIGHT: petitPacman.goRight();
					break;

				default:
					break;
				}				
			}
			SDL_Rect rect;
			rect.x = -5;
			rect.y = -5;
			SDL_BlitSurface(image, NULL, screenSurface, &rect);

		}
		closeWindow();
	}


	void WindowController::initWindow(){
		SDL_Init(SDL_INIT_EVERYTHING);
		window = SDL_CreateWindow("Pacman ce gros porc",
		                              SDL_WINDOWPOS_CENTERED,
		                              SDL_WINDOWPOS_CENTERED,
		                              685, 745,
		                              SDL_WINDOW_SHOWN);

		int imageFlag = IMG_INIT_PNG;
		IMG_Init(imageFlag);
		screenSurface = SDL_GetWindowSurface(window);
	}


	void WindowController::loadImage(Pacman petitPacman){
		image = loadSurface(petitPacman.getImage());
		if( image == NULL )
		{
			printf( "Failed to load PNG image!\n" );
		}
	}


	void WindowController::closeWindow(){
		SDL_FreeSurface(image);
		image = NULL;
	    SDL_DestroyWindow(window);
	    window = NULL;
	    IMG_Quit();
	    SDL_Quit();
	}


	SDL_Surface* WindowController::loadSurface(std::string path){
		loadedSurface = IMG_Load(path.c_str());
		optimizedSurface = SDL_ConvertSurface(loadedSurface, screenSurface->format, NULL);
		SDL_FreeSurface(loadedSurface);

		return optimizedSurface;
	}


