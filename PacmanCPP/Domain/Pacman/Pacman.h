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
using namespace std;

class Pacman
{
public:
	Pacman();
	Pacman(int x, int y);

	void setX(int x);
	void setY(int y);
	void setImage(string image);
	int getX() const;
	int getY() const;
	string getImage();

	void goUp();
	void goDown();
	void goLeft();
	void goRight();


private:
	int x,y;
	string image;
};

#endif /* PACMAN_H_ */
