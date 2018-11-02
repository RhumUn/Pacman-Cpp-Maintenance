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
	void Generate();
	string getLayoutLine(string line);
	int height = 22;
	int width = 20;
	std::vector<std::vector<Tile>> tiles;
};

#endif /* Map_H_ */