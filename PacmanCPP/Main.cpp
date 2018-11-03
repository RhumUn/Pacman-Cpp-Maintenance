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
#include "Domain/Map/Map.h"
#include "Domain/Pacman/Pacman.h"


using namespace std;


int main(int argc, char* argv[]) {

	Map map;
	map.Generate();
	Pacman pacman(map);
	WindowController window(pacman, map);

    return 0;
}
