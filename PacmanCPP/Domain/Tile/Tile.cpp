/*
 * Tile.cpp
 *
 *  Created on: 30 oct. 2018
 *      Author: Romain
 */

#include "Tile.h"

Tile::Tile(int _x, int _y, int _sprite) {
	x = _x;
	y = _y;
	sprite = _sprite;
}

int Tile::getX() {
	return this->x;
}

int Tile::getY() {
	return this->y;
}

int Tile::getSprite() {
	return this->sprite;
}

Tile::~Tile() {
	// TODO Auto-generated destructor stub
}

