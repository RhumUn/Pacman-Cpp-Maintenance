#include <iostream>
#include <SDL.h>
#include <SDL_image.h>
#include <stdio.h>
#include <string>
#include <windows.h>

#include "WindowController.h"


using namespace std;

	WindowController :: WindowController(){}

	void WindowController::create(){

		initWindow();
		SDL_Delay(5000);
		
		if( !loadImage() )
		{
			printf( "Failed to load media!\n" );
		}
		else
		{
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
			}
		}
		closeWindow();
	}


	void WindowController::initWindow(){
		SDL_Init(SDL_INIT_EVERYTHING);
		window = SDL_CreateWindow("Pacman ce gros porc",
		                              SDL_WINDOWPOS_CENTERED,
		                              SDL_WINDOWPOS_CENTERED,
		                              640, 480,
		                              SDL_WINDOW_SHOWN);

		int imageFlag = IMG_INIT_PNG;
		IMG_Init(imageFlag);
		screenSurface = SDL_GetWindowSurface(window);
	}


	bool WindowController::loadImage(){
		bool success = true;
		//Load PNG surface
		image = loadSurface("PacmanDown.PNG");
		if( image == NULL )
		{
			printf( "Failed to load PNG image!\n" );
			success = false;
		}
		return success;
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
		loadedSurface = IMG_Load("images/PacmanLeft.PNG");
		printf(IMG_GetError());
		optimizedSurface = SDL_ConvertSurface(loadedSurface, screenSurface->format, NULL);

		SDL_FreeSurface(loadedSurface);

		return optimizedSurface;
	}


