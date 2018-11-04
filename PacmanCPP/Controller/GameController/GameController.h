#ifndef GAMECONTROLLER_H_
#define GAMECONTROLLER_H_

#include <SDL.h>
#include <SDL_image.h>
#include <windows.h>
#include <stdio.h>
#include <string>
#include <vector>
#include <iostream>
#include "../../Domain/Pacman/Pacman.h"
#include "../../Domain/Tile/Tile.h"
#include "../../Domain/Map/Map.h"
#include "../../Domain/Score/Score.h"

class GameController
{
public:
	GameController();

	void play();

	void endOfGame();

	void closeWindow();

private:
	void initWindow();

	void updateWindow();

	void drawMap();

	void initSettingToDrawPacman();

	void drawPacman(SDL_Surface* pacmanSideSurface);

	void updateDisplayAfterPacmanMoved(SDL_Surface* pacmanSideSurface, SDL_Rect previousRectangleFilledWithPacman);

	SDL_Surface* createSDLSurface(std::string path);

	Pacman m_pacman;

	SDL_Window* m_SDLWindow;

	SDL_Renderer* m_SDLRenderer;

	SDL_Surface *m_SDLWindowSurface, *m_pacmanLeftSurface, *m_pacmanRightSurface, *m_pacmanUpSurface, *m_pacmanDownSurface;

	SDL_Rect m_rectangleFilledWithPacman;

	int m_nbCellsInHeight = 22, m_nbCellsInWidth = 20, m_cellSize = 32;
};

#endif /* GameController_H_ */
