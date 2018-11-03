#include "Tile.h"

Tile::Tile(bool isObstacle, bool isCollectible) : m_isObstacle(isObstacle), m_isCollectible(isCollectible) {
}

void Tile::setObstacleState(bool isObstacle)
{
	this->m_isObstacle = isObstacle;
}

void Tile::setCollectibleState(bool isCollectible)
{
	this->m_isCollectible = isCollectible;
}

bool Tile::isObstacle() {
	return this->m_isObstacle;
}

bool Tile::isCollectible() {
	return this->m_isCollectible;
}

