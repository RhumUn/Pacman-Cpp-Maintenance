#include <iostream>
#include <string>

#include "Pacman.h"
#include "../Map/Map.h"

using namespace std;
	 Pacman::Pacman(Map _map){
		 this->x = 6;
		 this->y = 6;
		 this->map = _map;
		 this->score = 0;
	 }

	 int Pacman::getX() const {
	 	return x;
	 }

	 void Pacman::setX(int x) {
	 	this->x = x;
	 }

	 int Pacman::getY() const {
	 	return y;
	 }

	 void Pacman::scoreUp(int tileX, int tileY)
	 {
		 this->score += 200;
		 map.tiles[tileX][tileY].setCollectibleState(false);
		 printf("Score: %i", this->score);
	 }

	 void Pacman::setY(int y) {
	 	this->y = y;
	 }

	 bool Pacman::goUp(){
		 if(!map.tiles[this->x][this->y - 1].isObstacle()){
			 if (map.tiles[this->x][this->y - 1].isCollectible()) {
				 scoreUp(this->x, this->y - 1);
			 }
			this-> y = y-1;
			return true;
		 }
		 return false;
	 }
	 bool Pacman::goDown(){
		 if (!map.tiles[this->x][this->y + 1].isObstacle()) {
			 if (map.tiles[this->x][this->y + 1].isCollectible()) {
				 scoreUp(this->x, this->y + 1);
			 }
			 this-> y = y+1;
			 return true;
		 }
		 return false;

	 }
	 bool Pacman::goLeft(){
		 if (!map.tiles[this->x  - 1][this->y].isObstacle()) {
			 if (map.tiles[this->x - 1][this->y].isCollectible()) {
				 scoreUp(this->x - 1, this->y);
			 }
			 this-> x = x-1;
			 return true;
		 }
		 return false;

	 }
	 bool Pacman::goRight(){
		 if (!map.tiles[this->x + 1][this->y].isObstacle()) {
			 if (map.tiles[this->x + 1][this->y].isCollectible()) {
				 scoreUp(this->x + 1, this->y);
			 }
			 this-> x = x+1;
			 return true;
		 }
		 return false;
	 }

