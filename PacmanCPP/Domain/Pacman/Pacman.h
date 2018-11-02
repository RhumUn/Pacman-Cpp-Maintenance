/*
 * Pacman.h
 *
 *  Created on: 23 oct. 2018
 *      Author: Popclem
 */

#ifndef PACMAN_H
#define PACMAN_H


#include <iostream>
#include <string>
#include "../Map/Map.h"
using namespace std;

class Pacman
{
public:
	Pacman(Map _map);
	void setX(int x);
	void setY(int y);
	int getX() const;
	int getY() const;
	void scoreUp(int tileX, int tileY);
	bool goUp();
	bool goDown();
	bool goLeft();
	bool goRight();
	int x, y;
	int score;

private:
	Map map;
	string image;
};

#endif /* PACMAN_H_ */
