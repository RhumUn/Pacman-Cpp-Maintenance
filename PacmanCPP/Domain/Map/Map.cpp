/*
 * Map.cpp
 *
 *  Created on: 30 oct. 2018
 *      Author: Romain
 */
#include <iostream>
#include <iomanip>
#include <algorithm>
#include <iostream>
#include <string>
#include <vector>
#include "../Map/Map.h"
#include "../Tile/Tile.h"
using namespace std;

Map::Map() {
	tiles = std::vector<std::vector<Tile>>(height);
}

Map::~Map() {
	// TODO Auto-generated destructor stub
}

void Map::Generate() {
	string	layout[36];

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

	string layoutLine;

	for (i = 0; i < height; i++) {
		layoutLine = getLayoutLine(layout[i]);
		for (j = 0; j < width; j++)
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
			tiles[i].push_back(Tile(j, i, isObstacle, isCollectible));
		}
	}
}

string Map::getLayoutLine(string line)
{
	line.erase(std::remove(line.begin(), line.end(), ','), line.end());
	line.erase(std::remove(line.begin(), line.end(), '\n'), line.end());
	return line;
}
