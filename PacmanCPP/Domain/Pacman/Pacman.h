#ifndef PACMAN_H
#define PACMAN_H

#include "../Map/Map.h"
#include "../Score/Score.h"

class Pacman
{
public:
	Pacman();

	void setX(int x);

	void setY(int y);

	int getX() const;

	int getY() const;

	Map getMap() const;

	Score getScore() const;

	bool moveUp();

	bool moveDown();

	bool moveLeft();

	bool moveRight();

	bool isEndOfGame();

private:
	bool move(int nextXPos, int nextYPos);

	Map m_map;

	std::string m_imagePath;

	int m_x, m_y;

	Score m_score;
};

#endif /* PACMAN_H_ */
