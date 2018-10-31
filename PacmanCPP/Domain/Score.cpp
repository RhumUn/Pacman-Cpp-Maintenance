/*
 * Score.cpp
 *
 *  Created on: 31 oct. 2018
 *      Author: vicdo
 */

#include "Score.h"
#include "../FileStream/OutFileStream.h"
#include <string>

Score::Score(std::string playerName) :
		m_score(0), m_playerName(playerName) {
}

Score::~Score() {
	Score::saveScore();
}

int Score::getScore(){
	return m_score;
}

void Score::updateScore(int increment){
	Score::m_score += increment;
}

void Score::saveScore(){
	OutFileStream scoreSaver("Resources/Score.txt");

	scoreSaver.write(Score::toString());
}

std::string Score::toString() {
	return "Score actuel : " + std::to_string(Score::m_score);
}

