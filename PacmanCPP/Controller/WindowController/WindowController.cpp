#include <iostream>
#include <SDL.h>
#include <SDL_image.h>
#include <stdio.h>
#include <string>
#include <windows.h>

#include "WindowController.h"
#include "../ActionController/ActionController.h"
#include "../../Domain/Pacman/Pacman.h"7

using namespace std;

	WindowController :: WindowController(){}

	void WindowController::create(){

		initWindow();
		loadImage();
	
			bool quit = false;
			SDL_Event e;

			while( !quit )
			{
				while( SDL_PollEvent( &e ) != 0 )
				{
					if( e.type == SDL_QUIT )
					{
						quit = true;
					}
				}

				SDL_BlitSurface(image, NULL, screenSurface, NULL);
				SDL_UpdateWindowSurface(window);

				Pacman petitPacman(6,6);
				ActionController action(petitPacman);
				action.mouvement(e);
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


	void WindowController::loadImage(){

		image = loadSurface("Resources/Map.PNG");
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
		printf(IMG_GetError());
		optimizedSurface = SDL_ConvertSurface(loadedSurface, screenSurface->format, NULL);

		SDL_FreeSurface(loadedSurface);

		return optimizedSurface;
	}


