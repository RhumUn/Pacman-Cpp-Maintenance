/*
 * ActionController.h
 *
 *  Created on: 24 oct. 2018
 *      Author: Popclem
 */

#ifndef ACTIONCONTROLLER_H_
#define ACTIONCONTROLLER_H_

#include <iostream>
#include "Pacman.h"

using namespace std;

class ActionController
{
public:
	ActionController();
	ActionController(Pacman pacman);

	void mouvement();

private:
	Pacman pacman;
	SDL_Event e;
	bool quit = false;
};
#endif /* CONTROLLER_ACTIONCONTROLLER_H_ */
