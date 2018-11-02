/*
 * Score.h
 *
 *  Created on: 31 oct. 2018
 *      Author: vicdo
 */

#ifndef DOMAIN_SCORE_H_
#define DOMAIN_SCORE_H_

#include <string>
#include<vector>

static class Score {
public:
	Score();

	int getScore();

	void updateScore(int increment);

	void saveScore();

private:
	int m_score;

	std::vector<std::string> get5BestScores();

	int getScoreValue(std::string scoreSavedInString);

	bool isOneOf5BestScores(std::vector<std::string> const& vectorOf5BestScores);

	std::string scoresContentsToSave(std::vector<std::string> vectorOf5BestScores);

	std::string toString();
};

#endif /* DOMAIN_SCORE_H_ */
