#include "Controller/GameController/GameController.h"
#include "Domain/Map/Map.h"
#include "Domain/Pacman/Pacman.h"

using namespace std;

int main(int argc, char* argv[]) {
	GameController game;

	game.play();

	game.endOfGame();

	game.closeWindow();

	return 0;
}
