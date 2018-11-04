#include "../Map/Map.h"

Map::Map() {
}

Tile& Map::getTile(int x, int y) {
	return this->m_tiles[x][y];
}

std::vector<std::vector<Tile>> Map::getTiles() {
	return this->m_tiles;
}

int Map::getNbCollectiblesToEat() {
	return this->m_nbCollectiblesToEat;
}

void Map::decrementCollectiblesToEat() {
	this->m_nbCollectiblesToEat--;
}

void Map::Generate() {
	std::vector<std::string> layout = InFileStream("Resources/mapOpen.map").readLineByLine();

	int i, j;
	bool isObstacle, isCollectible;
	std::string layoutLine;

	for (i = 0; i < layout.size(); i++) {
		layoutLine = getLayoutLine(layout[i]);

		this->m_tiles.push_back(std::vector<Tile>());

		for (j = 0; j < layoutLine.size(); j++)
		{
			isObstacle = false;
			isCollectible = false;

			if (layoutLine.at(j) == '1') {
				isObstacle = true;
			}
			else if (layoutLine.at(j) == '2')
			{
				isCollectible = true;
				this->m_nbCollectiblesToEat++;
			}

			this->m_tiles[i].push_back(Tile(isObstacle, isCollectible));
		}
	}
}

std::string Map::getLayoutLine(std::string line) {
	line.erase(std::remove(line.begin(), line.end(), ','), line.end());

	return line;
}
