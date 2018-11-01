/*
 * Map.cpp
 *
 *  Created on: 30 oct. 2018
 *      Author: Romain
 */
#include <iostream>
#include <iomanip>
#include <vector>
#include "../Map/Map.h"
#include "../Tile/Tile.h"
using namespace std;

Map::Map() {
	cout << "Generator created";
}

Map::~Map() {
	// TODO Auto-generated destructor stub
}

int Map::GenerateMap() {
	 cout << "Map generation";
	 std::vector<std::vector<Tile>> map(32);
	 int i, j;
	 for (i=0; i<height; i++){
	    for (j=0; j<width; j++)
	    {
	    	map[i].push_back(Tile(j, i, 0));
	    }
     }

	 for (int i = 0; i < height; i++) {
	     for (int j = 0; j < width; j++) {
	    	 cout << "Case de coordonnées: " <<  map[i][j].getX() << ", " << map[i][j].getY();
	     }
	 }
	 return 0;
}
