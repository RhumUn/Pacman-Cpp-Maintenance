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

#include "Domain/Pacman/Pacman.h"
//#include "Controller/ActionController/ActionController.h"
#include "Controller/WindowController/WindowController.h"

using namespace std;


int main(int argc, char* argv[]) {

	//Pacman petitPacman(6,6);
	//ActionController action(petitPacman);
	WindowController window;
	window.create();
  	//action.mouvement();
    return 0;
}
