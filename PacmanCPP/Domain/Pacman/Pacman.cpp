#include <iostream>
#include <string>

#include "Pacman.h"

using namespace std;


	 Pacman::Pacman(): x(0), y(0){}
	 Pacman::Pacman(int x, int y) : x(x), y(y){}


	 int Pacman::getX() const {
	 	return x;
	 }

	 void Pacman::setX(int x) {
	 	this->x = x;
	 }

	 int Pacman::getY() const {
	 	return y;
	 }

	 void Pacman::setY(int y) {
	 	this->y = y;
	 }

	 string Pacman::getImage() {
	 	return image;
	 }

	 void Pacman::setImage(string image) {
	 	this->image = image;
	 }



	 void Pacman::goUp(){
		// if(y + 1 < getYMap){
			this-> y = y+1;
			 this-> image = "Resources/PacmanUp.PNG";
		 //}
	 }
	 void Pacman::goDown(){
		// if(y - 1 < getYMap){
			this-> y = y-1;
			this-> image = "Resources/PacmanDown.PNG";
		// }
	 }
	 void Pacman::goLeft(){
		 //if(x - 1 < getYMap){
			this-> x = x-1;
			this-> image = "Resources/PacmanLeft.PNG";
		// }
	 }
	 void Pacman::goRight(){
		 //if(x - 1 < getYMap){
			this-> x = x+1;
			this-> image = "Resources/PacmanRight.PNG";
		 //}
	 }

