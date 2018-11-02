/*
 * WindowController.h
 *
 *  Created on: 31 oct. 2018
 *      Author: Popclem
 */

#ifndef WINDOWCONTROLLER_H_
#define WINDOWCONTROLLER_H_

#include <iostream>

#include "../../Domain/Pacman/Pacman.h"


#include "../../Domain/Tile/Tile.h"

using namespace std;


class WindowController
{
public:
	WindowController();

	void create(Pacman pacman);
	void initWindow();
	void loadImage(Pacman pacman);
	void closeWindow();
	void loadMap(SDL_Renderer *renderer);
	SDL_Surface* loadSurface(std::string path);

private:
	SDL_Window* window = NULL;
	SDL_Surface* screenSurface = NULL;
	SDL_Surface* image = NULL;
	SDL_Surface* optimizedSurface = NULL;
	SDL_Surface* loadedSurface = NULL;
	int heigth = 22;
	int width = 20;
	int obstacleSize = 32;
	SDL_Event e;
};


#endif /* WINDOWCONTROLLER_H_ */
