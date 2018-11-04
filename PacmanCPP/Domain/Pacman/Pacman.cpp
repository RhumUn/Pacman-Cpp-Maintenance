#include<iostream>

#include "Pacman.h"

Pacman::Pacman() : m_x(6), m_y(6), m_map(), m_score() {
	this->m_map.Generate();
}

int Pacman::getX() const {
	return this->m_x;
}

void Pacman::setX(int x) {
	this->m_x = x;
}

int Pacman::getY() const {
	return this->m_y;
}

void Pacman::setY(int y) {
	this->m_y = y;
}

Map Pacman::getMap() const{
	return this->m_map;
}

Score Pacman::getScore() const {
	return this->m_score;
}

bool Pacman::moveUp() {
	return Pacman::move(this->m_x, this->m_y - 1);
}
bool Pacman::moveDown() {
	return Pacman::move(this->m_x, this->m_y + 1);

}
bool Pacman::moveLeft() {
	return Pacman::move(this->m_x - 1, this->m_y);

}
bool Pacman::moveRight() {
	return Pacman::move(this->m_x + 1, this->m_y);
}

bool Pacman::move(int nextPosX, int nextPosY) {
	Tile& nextTile = this->m_map.getTile(nextPosX, nextPosY);

	if (nextTile.isObstacle()) {
		return false;
	}

	if (nextTile.isCollectible()) {
		this->m_score.updateScore(100);

		nextTile.setCollectibleState(false);

		this->m_map.decrementCollectiblesToEat();
	}

	this->m_x = nextPosX;
	this->m_y = nextPosY;

	return true;
}

bool Pacman::isEndOfGame() {
	return this->m_map.getNbCollectiblesToEat() == 0;
}


