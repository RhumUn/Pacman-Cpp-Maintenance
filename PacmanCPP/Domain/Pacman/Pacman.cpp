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
	if (m_map.getTile(nextPosX, nextPosY).isObstacle()) {
		return false;
	}

	if (m_map.getTile(nextPosX, nextPosY).isCollectible()) {
		this->m_score.updateScore(200);

		this->m_map.getTile(nextPosX, nextPosY).setCollectibleState(false);
	}

	this->m_x = nextPosX;
	this->m_y = nextPosY;

	return true;
}


