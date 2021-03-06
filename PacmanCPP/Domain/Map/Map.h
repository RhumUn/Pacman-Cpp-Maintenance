#ifndef Map_H_
#define Map_H_

#include <algorithm>
#include<string>
#include <vector>
#include "../Tile/Tile.h"
#include "../../FileStream/InFileStream/InFileStream.h"

class Map {
public:
	Map();

	Tile& getTile(int x, int y);

	std::vector<std::vector<Tile>> getTiles();

	int getNbCollectiblesToEat();

	void decrementCollectiblesToEat();

	void Generate();

private:
	std::string getLayoutLine(std::string line);

	int m_nbCollectiblesToEat = 0;

	std::vector<std::vector<Tile>> m_tiles;
};

#endif /* Map_H_ */