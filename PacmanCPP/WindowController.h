/*
 * WindowController.h
 *
 *  Created on: 31 oct. 2018
 *      Author: Popclem
 */

#ifndef WINDOWCONTROLLER_H_
#define WINDOWCONTROLLER_H_

#include <iostream>
using namespace std;


class WindowController
{
public:
	WindowController();

	void create();
	void initWindow();
	bool loadImage();
	void closeWindow();
	SDL_Surface* loadSurface(std::string path);

private:
	SDL_Window* window = NULL;
	SDL_Surface* screenSurface = NULL;
	SDL_Surface* image = NULL;
	SDL_Surface* optimizedSurface = NULL;
	SDL_Surface* loadedSurface = NULL;
};


#endif /* WINDOWCONTROLLER_H_ */
