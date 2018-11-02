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

using namespace std;


int main(int argc, char* argv[]) {

	WindowController window;
	window.create();

    return 0;
}
