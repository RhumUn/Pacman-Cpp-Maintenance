#ifndef PACMAN_H
#define PACMAN_H

#include "../Map/Map.h"
#include "../Score/Score.h"

class Pacman
{
public:
	Pacman(Map _map);

	void setX(int x);

	void setY(int y);

	int getX() const;

	int getY() const;

	bool moveUp();

	bool moveDown();

	bool moveLeft();

	bool moveRight();
	
	bool move(int nextXPos, int nextYPos);


private:
	Map m_map;

	std::string m_imagePath;

	int m_x, m_y;

	Score m_score;
};

#endif /* PACMAN_H_ */
