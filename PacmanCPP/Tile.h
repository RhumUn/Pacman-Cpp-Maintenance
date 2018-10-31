/*
 * Tile.h
 *
 *  Created on: 30 oct. 2018
 *      Author: Romain
 */
#include <iostream>
#include <string>

#ifndef TILE_H_
#define TILE_H_

class Tile {
public:
	Tile();
	Tile(int _x, int _y, int _sprite);
	virtual ~Tile();
	int getX();
	int getY();
	int getSprite();
	int x;
	int y;
	int sprite;
};

#endif /* TILE_H_ */
