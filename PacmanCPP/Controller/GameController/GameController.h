#ifndef GAMECONTROLLER_H_
#define GAMECONTROLLER_H_

#include <SDL.h>
#include <SDL_image.h>
#include <stdio.h>
#include <string>
#include <windows.h>
#include <vector>
#include <iostream>
#include "../../Domain/Pacman/Pacman.h"
#include "../../Domain/Tile/Tile.h"
#include "../../Domain/Map/Map.h"

class GameController
{
public:
	GameController();

private:
	void initWindow();

	void updateWindow();

	void drawMap();

	void initSettingToDrawPacman();

	void drawPacman(SDL_Surface* pacmanSideSurface);

	void updateDisplayAfterPacmanMoved(SDL_Surface* pacmanSideSurface, SDL_Rect previousRectangleFilledWithPacman);

	SDL_Surface* createSDLSurface(std::string path);

	void closeWindow();

	Pacman m_pacman;

	SDL_Window* m_SDLWindow;

	SDL_Renderer* m_SDLRenderer;

	SDL_Surface* m_SDLWindowSurface;

	SDL_Surface* m_pacmanLeftSurface;

	SDL_Surface* m_pacmanRightSurface;

	SDL_Surface* m_pacmanUpSurface;

	SDL_Surface * m_pacmanDownSurface;

	SDL_Rect m_rectangleFilledWithPacman;

	int m_nbCellsInHeight = 22, m_nbCellsInWidth = 20, m_cellSize = 32;

	//A supprimer 
	SDL_Surface* image = NULL;
};


#endif /* GameController_H_ */
