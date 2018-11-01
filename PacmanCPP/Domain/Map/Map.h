/*
 * Map.h
 *
 *  Created on: 30 oct. 2018
 *      Author: Romain
 */

#ifndef Map_H_
#define Map_H_
#include "../Tile/Tile.h"
#include <vector>
using namespace std;

class Map {
public:
	Map();
	virtual ~Map();
	int GenerateMap();
	int height = 28;
	int width = 31;
	std::vector<std::vector<Tile>> tiles;
};

#endif /* Map_H_ */
