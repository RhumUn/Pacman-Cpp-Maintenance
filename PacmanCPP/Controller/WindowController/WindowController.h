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
#include "../../Domain/Map/Map.h"


using namespace std;


class WindowController
{
public:
	WindowController(Pacman pacman, Map _map);
	void initWindow();
	void closeWindow();
	void updateWindow();
	void loadMap();
	void loadPacman(Pacman pacman);
	void updatePacman(Pacman pacman);
	SDL_Surface* loadSurface(std::string path);

private:
	SDL_Window* window = NULL;
	SDL_Renderer* renderer = NULL;
	SDL_Surface* screenSurface = NULL;
	SDL_Surface* image = NULL;
	SDL_Surface* optimizedSurface = NULL;
	SDL_Surface* loadedSurface = NULL;
	SDL_Texture* pacmanTexture = NULL;
	SDL_Surface* pacmanSurfaceLeft;
	SDL_Surface* pacmanSurfaceRight;
	SDL_Surface* pacmanSurfaceUp;
	SDL_Surface * pacmanSurfaceDown;
	SDL_Rect pacmanPosition;
	Map map;
	int heigth = 22;
	int width = 20;
	int objectSize = 32;
	SDL_Event e;
};


#endif /* WINDOWCONTROLLER_H_ */
