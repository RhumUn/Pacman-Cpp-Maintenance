#include <iostream>
#include <SDL.h>
#include <SDL_image.h>
#include <stdio.h>
#include <string>
#include <windows.h>
#include <vector>

#include "WindowController.h"
#include "../../Domain/Tile/Tile.h"
#include "../../Domain/Map/Map.h"

using namespace std;

WindowController::WindowController() {}

void WindowController::create() {

	initWindow();
	SDL_Delay(5000);
	SDL_Renderer *renderer = SDL_CreateRenderer(window, -1, SDL_RENDERER_ACCELERATED);
	loadMap(renderer);
	//if (!loadImage())
	//{
	//	printf("Failed to load media!\n");
	//}
	//else
	//{
	//	bool quit = false;
	//	SDL_Event e;

	//	while (!quit)
	//	{
	//		while (SDL_PollEvent(&e) != 0)
	//		{
	//			if (e.type == SDL_QUIT)
	//			{
	//				quit = true;
	//			}
	//		}

	//		SDL_BlitSurface(image, NULL, screenSurface, NULL);
	//		SDL_UpdateWindowSurface(window);
	//	}
	//}
	//closeWindow();
}


void WindowController::initWindow() {
	SDL_Init(SDL_INIT_EVERYTHING);
	window = SDL_CreateWindow("Pacman ce gros porc",
		SDL_WINDOWPOS_CENTERED,
		SDL_WINDOWPOS_CENTERED,
		heigth * obstacleSize, width * obstacleSize,
		SDL_WINDOW_SHOWN);

	int imageFlag = IMG_INIT_PNG;
	IMG_Init(imageFlag);
	screenSurface = SDL_GetWindowSurface(window);
}


bool WindowController::loadImage() {
	bool success = true;
	//Load PNG surface
	image = loadSurface("PacmanDown.PNG");
	if (image == NULL)
	{
		printf("Failed to load PNG image!\n");
		success = false;
	}
	return success;
}

void WindowController::loadMap(SDL_Renderer *renderer) {
	Map map;
	map.Generate();
	std::vector<std::vector<Tile>> tilesMap = map.tiles;

	SDL_Surface* obstacleTileSurface = loadSurface("Resources/obstacle_tile.png");
	SDL_Surface* collectibleTileSurface = loadSurface("Resources/collectible_tile.png");

	SDL_Texture* obstacleTileTexture = SDL_CreateTextureFromSurface(renderer, obstacleTileSurface);
	SDL_Texture* collectibleTileTexture = SDL_CreateTextureFromSurface(renderer, collectibleTileSurface);


	SDL_Rect tilePosition;
	tilePosition.h = obstacleSize;
	tilePosition.w = obstacleSize;
	for (int i = 0; i < heigth; i++) {
		for (int j = 0; j < width; j++) {
			tilePosition.x = i * obstacleSize;
			tilePosition.y = j * obstacleSize;
			if (tilesMap[i][j].isObstacle()) {
				SDL_RenderCopy(renderer, obstacleTileTexture, NULL, &tilePosition);
			}
			else if (tilesMap[i][j].isCollectible()) {
				SDL_RenderCopy(renderer, collectibleTileTexture, NULL, &tilePosition);
			}
			else {
				SDL_RenderCopy(renderer, NULL, NULL, &tilePosition);
			}
		}
	}
	SDL_RenderPresent(renderer);
}
void WindowController::closeWindow() {
	SDL_FreeSurface(image);
	image = NULL;
	SDL_DestroyWindow(window);
	window = NULL;
	IMG_Quit();
	SDL_Quit();
}


SDL_Surface* WindowController::loadSurface(std::string path) {
	loadedSurface = IMG_Load(path.c_str());
	printf(IMG_GetError());
	optimizedSurface = SDL_ConvertSurface(loadedSurface, screenSurface->format, NULL);

	SDL_FreeSurface(loadedSurface);

	return optimizedSurface;
}


