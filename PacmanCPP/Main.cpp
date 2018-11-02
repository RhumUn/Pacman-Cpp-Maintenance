//============================================================================
// Name        : SDLTest.cpp
// Author      :
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================
//test

#include <iostream>
#include <windows.h>
#include <SDL.h>

#include "Controller/WindowController/WindowController.h"
#include "Domain/Pacman/Pacman.h"


using namespace std;


int main(int argc, char* argv[]) {

	Pacman petitPacman(6, 6);
	petitPacman.setImage("Resources/PacmanLeft.PNG");
	WindowController window;
	window.create(petitPacman);

    return 0;
}
