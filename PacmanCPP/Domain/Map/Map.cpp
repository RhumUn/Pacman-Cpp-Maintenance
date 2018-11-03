#include "../Map/Map.h"

Map::Map() : m_tiles(std::vector<std::vector<Tile>>(this->m_height)) {
}

Tile Map::getTile(int x, int y) {
	return this->m_tiles[x][y];
}

std::vector<std::vector<Tile>> Map::getTiles() {
	return this->m_tiles;
}

void Map::Generate() {
	std::string	layout[36];

	//TODO Utiliser inFileStream
	layout[0] = "1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1";
	layout[1] = "1,2,2,2,2,2,2,2,2,1,1,2,2,2,2,2,2,2,2,1";
	layout[2] = "1,2,1,1,2,1,1,1,2,1,1,2,1,1,1,2,1,1,2,1";
	layout[3] = "1,2,1,1,2,1,1,1,2,1,1,2,1,1,1,2,1,1,2,1";
	layout[4] = "1,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,1";
	layout[5] = "1,2,1,1,2,1,2,1,1,1,1,1,1,2,1,2,1,1,2,1";
	layout[6] = "1,2,2,2,2,1,2,2,2,1,1,2,2,2,1,2,2,2,2,1";
	layout[7] = "1,1,1,1,2,1,1,1,2,1,1,2,1,1,1,2,1,1,1,1";
	layout[8] = "0,0,0,1,2,1,2,2,2,2,2,2,2,2,1,2,1,0,0,0";
	layout[9] = "0,0,0,1,2,1,2,1,1,0,0,1,1,2,1,2,1,0,0,0";
	layout[10] = "0,0,0,1,2,2,2,1,0,0,0,0,1,2,2,2,1,0,0,0";
	layout[11] = "0,0,0,1,2,1,2,1,1,1,1,1,1,2,1,2,1,0,0,0";
	layout[12] = "0,0,0,1,2,1,2,2,2,2,0,2,2,2,1,2,1,0,0,0";
	layout[13] = "1,1,1,1,2,1,2,1,1,1,1,1,1,2,1,2,1,1,1,1";
	layout[14] = "1,2,2,2,2,2,2,2,2,1,1,2,2,2,2,2,2,2,2,1";
	layout[15] = "1,2,1,1,2,1,1,1,2,1,1,2,1,1,1,2,1,1,2,1";
	layout[16] = "1,2,2,1,2,2,2,2,2,2,2,2,2,2,2,2,1,2,2,1";
	layout[17] = "1,1,2,1,2,1,2,1,1,1,1,1,1,2,1,2,1,2,1,1";
	layout[18] = "1,2,2,2,2,1,2,2,2,1,1,2,2,2,1,2,2,2,2,1";
	layout[19] = "1,2,1,1,1,1,1,1,2,1,1,2,1,1,1,1,1,1,2,1";
	layout[20] = "1,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,1";
	layout[21] = "1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1";
	int i, j;
	bool isObstacle;
	bool isCollectible;

	std::string layoutLine;

	for (i = 0; i < this->m_height; i++) {
		layoutLine = getLayoutLine(layout[i]);
		for (j = 0; j < this->m_width; j++)
		{
			if (layoutLine.at(j) == '1') {
				isObstacle = true;
				isCollectible = false;
			}
			else if (layoutLine.at(j) == '2')
			{
				isObstacle = false;
				isCollectible = true;
			}
			else {
				isObstacle = false;
				isCollectible = false;
			}
			this->m_tiles[i].push_back(Tile(isObstacle, isCollectible));
		}
	}
}

std::string Map::getLayoutLine(std::string line)
{
	line.erase(std::remove(line.begin(), line.end(), ','), line.end());

	return line;
}
