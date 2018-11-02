/*
 * Tile.cpp
 *
 *  Created on: 30 oct. 2018
 *      Author: Romain
 */

#include "Tile.h"

Tile::Tile(int _x, int _y, bool _obstacleState, bool _collectibleState) {
	x = _x;
	y = _y;
	obstacleState = _obstacleState;
	collectibleState = _collectibleState;
}

int Tile::getX() {
	return this->x;
}

int Tile::getY() {
	return this->y;
}

void Tile::setObstacleState(bool _obstacleState)
{
	this->obstacleState = _obstacleState;
}

void Tile::setCollectibleState(bool _collectibleState)
{
	this->collectibleState= _collectibleState;
}

bool Tile::isObstacle() {
	return this->obstacleState;
}

bool Tile::isCollectible() {
	return this->collectibleState;
}

Tile::~Tile() {
	// TODO Auto-generated destructor stub
}

