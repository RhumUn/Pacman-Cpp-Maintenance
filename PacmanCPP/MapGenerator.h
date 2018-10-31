/*
 * MapGenerator.h
 *
 *  Created on: 30 oct. 2018
 *      Author: Romain
 */

#ifndef MAPGENERATOR_H_
#define MAPGENERATOR_H_
#include "Tile.h"
#include <vector>
using namespace std;

class MapGenerator {
public:
	MapGenerator();
	virtual ~MapGenerator();
	int GenerateMap();
	int height = 28;
	int width = 31;
	std::vector<std::vector<Tile>> tiles;
};

#endif /* MAPGENERATOR_H_ */
