/*
 * Score.h
 *
 *  Created on: 31 oct. 2018
 *      Author: vicdo
 */

#ifndef DOMAIN_SCORE_H_
#define DOMAIN_SCORE_H_

#include <string>

class Score {
public:
	Score(std::string playerName);

	virtual ~Score();

	int getScore();

	void updateScore(int increment);

	void saveScore();

	std::string toString();

private:
	int m_score;

	std::string m_playerName;
};

#endif /* DOMAIN_SCORE_H_ */
