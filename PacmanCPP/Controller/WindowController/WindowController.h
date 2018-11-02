/*
 * WindowController.h
 *
 *  Created on: 31 oct. 2018
 *      Author: Popclem
 */

#ifndef WINDOWCONTROLLER_H_
#define WINDOWCONTROLLER_H_

#include <iostream>
#include "../../Domain/Tile/Tile.h"

using namespace std;


class WindowController
{
public:
	WindowController();

	void create();
	void initWindow();
	bool loadImage();
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
};


#endif /* WINDOWCONTROLLER_H_ */
