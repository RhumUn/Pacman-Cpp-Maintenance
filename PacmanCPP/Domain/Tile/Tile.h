#ifndef TILE_H_
#define TILE_H_

class Tile {
public:
	Tile(bool isObstacle, bool isCollectible);

	void setObstacleState(bool isObstacle);

	void setCollectibleState(bool isCollectible);

	bool isObstacle();

	bool isCollectible();
private:
	bool m_isObstacle;

	bool m_isCollectible;
};

#endif /* TILE_H_ */
