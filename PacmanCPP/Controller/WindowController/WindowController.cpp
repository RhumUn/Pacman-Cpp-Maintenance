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
#include "../../Domain/Pacman/Pacman.h"

using namespace std;

WindowController::WindowController(Pacman petitPacman, Map _map) {
	initWindow();
	loadMap();
	loadPacman(petitPacman);
	bool quit = false;
	SDL_Rect pacmanPreviousPosition;
	pacmanPreviousPosition.h = objectSize;
	pacmanPreviousPosition.w = objectSize;

	SDL_Surface* emptyTileSurface = SDL_CreateRGBSurface(0, objectSize, objectSize, 32, 0, 0, 0, 0);
	SDL_Texture* emptyTileTexture = SDL_CreateTextureFromSurface(renderer, emptyTileSurface);


	while (!quit)
	{
		while (SDL_PollEvent(&e) != 0)
		{
			if (e.type == SDL_QUIT)
			{
				quit = true;
			}
		}

		if (e.type == SDL_KEYDOWN)
		{
			pacmanPreviousPosition.x = petitPacman.getX() * objectSize;
			pacmanPreviousPosition.y = petitPacman.getY() * objectSize;
			switch (e.key.keysym.sym)
			{
			case SDLK_UP:
				if (petitPacman.moveUp()) {
					this->pacmanTexture = SDL_CreateTextureFromSurface(renderer, this->pacmanSurfaceUp);
					SDL_RenderCopy(this->renderer, emptyTileTexture, NULL, &pacmanPreviousPosition);
					updatePacman(petitPacman);
				}
				break;

			case SDLK_DOWN:
				if (petitPacman.moveDown()) {
					this->pacmanTexture = SDL_CreateTextureFromSurface(renderer, this->pacmanSurfaceDown);
					SDL_RenderCopy(this->renderer, emptyTileTexture, NULL, &pacmanPreviousPosition);
					updatePacman(petitPacman);
				}
				break;

			case SDLK_LEFT:
				if (petitPacman.moveLeft()) {
					this->pacmanTexture = SDL_CreateTextureFromSurface(renderer, this->pacmanSurfaceLeft);
					SDL_RenderCopy(this->renderer, emptyTileTexture, NULL, &pacmanPreviousPosition);
					updatePacman(petitPacman);
				}
				break;

			case SDLK_RIGHT:
				if (petitPacman.moveRight()) {
					this->pacmanTexture = SDL_CreateTextureFromSurface(renderer, this->pacmanSurfaceRight);
					SDL_RenderCopy(this->renderer, emptyTileTexture, NULL, &pacmanPreviousPosition);
					updatePacman(petitPacman);
				}
				break;

			default:
				break;
			}
			updateWindow();

			SDL_Delay(100);
		}
	}
	closeWindow();
}

void WindowController::initWindow() {
	SDL_Init(SDL_INIT_EVERYTHING);
	window = SDL_CreateWindow("Pacman ce gros porc",
		SDL_WINDOWPOS_CENTERED,
		SDL_WINDOWPOS_CENTERED,
		heigth * objectSize, width * objectSize,
		SDL_WINDOW_SHOWN);
	this->renderer = SDL_CreateRenderer(window, -1, 0);
	SDL_RenderClear(renderer);
	int imageFlag = IMG_INIT_PNG;
	IMG_Init(imageFlag);
	screenSurface = SDL_GetWindowSurface(window);
}

void WindowController::updateWindow() {
	SDL_RenderPresent(this->renderer);
}

void WindowController::loadMap() {
	this->map.Generate();
	std::vector<std::vector<Tile>> tilesMap = map.getTiles();

	SDL_Surface* obstacleTileSurface = loadSurface("Resources/obstacle_tile.png");
	SDL_Surface* collectibleTileSurface = loadSurface("Resources/collectible_tile.png");

	SDL_Texture* obstacleTileTexture = SDL_CreateTextureFromSurface(renderer, obstacleTileSurface);
	SDL_Texture* collectibleTileTexture = SDL_CreateTextureFromSurface(renderer, collectibleTileSurface);


	SDL_Rect tilePosition;
	tilePosition.h = objectSize;
	tilePosition.w = objectSize;
	for (int i = 0; i < heigth; i++) {
		for (int j = 0; j < width; j++) {
			tilePosition.x = i * objectSize;
			tilePosition.y = j * objectSize;
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
	updateWindow();
}

void WindowController::loadPacman(Pacman pacman)
{
	this->pacmanSurfaceLeft = loadSurface("Resources/PacmanLeft.png");
	this->pacmanSurfaceRight = loadSurface("Resources/PacmanRight.png");
	this->pacmanSurfaceUp = loadSurface("Resources/PacmanUp.png");
	this->pacmanSurfaceDown = loadSurface("Resources/PacmanDown.png");
	this->pacmanTexture = SDL_CreateTextureFromSurface(renderer, pacmanSurfaceLeft);

	this->pacmanPosition;
	this->pacmanPosition.h = objectSize;
	this->pacmanPosition.w = objectSize;
	this->pacmanPosition.x = pacman.getX() * objectSize;
	this->pacmanPosition.y = pacman.getY() * objectSize;

	SDL_RenderCopy(renderer, pacmanTexture, NULL, &pacmanPosition);
	updateWindow();
}

void WindowController::updatePacman(Pacman pacman)
{
	this->pacmanPosition.x = pacman.getX() * objectSize;
	this->pacmanPosition.y = pacman.getY() * objectSize;

	SDL_RenderCopy(this->renderer, this->pacmanTexture, NULL, &this->pacmanPosition);
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


