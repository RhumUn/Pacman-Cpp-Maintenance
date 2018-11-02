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
	Tile(int _x, int _y, bool _sprite, bool _collectibleState);
	virtual ~Tile();
	int getX();
	int getY();
	void setObstacleState(bool _obstacleState);
	void setCollectibleState(bool _collectibleState);
	bool isObstacle();
	bool isCollectible();
private:
	int x;
	int y;
	bool obstacleState;
	bool collectibleState;
};

#endif /* TILE_H_ */
