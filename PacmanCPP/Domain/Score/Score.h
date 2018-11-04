#ifndef DOMAIN_SCORE_H_
#define DOMAIN_SCORE_H_

#include <string>
#include<vector>
#include "../Time/Time.h"
#include "../../FileStream/OutFileStream/OutFileStream.h"
#include "../../FileStream//InFileStream/InFileStream.h"

class Score {
public:
	Score();

	int getScore();

	void updateScore(int increment);

	void saveScore();

	std::string getScoreInformationToString();

	std::string get5BestScoresToString();

	void setTimer();

	void setFinalScore();

private:
	std::vector<std::string> get5BestScores();

	int getScoreValue(std::string scoreSavedInString);

	bool isOneOf5BestScores(std::vector<std::string> const& vectorOf5BestScores);

	std::string scoresContentsToSave(std::vector<std::string> vectorOf5BestScores);

	std::string scoreToStringForSaving();

	int m_score;

	Time m_timeAtGameLaunch;

	int m_timerInSeconds;
};

#endif /* DOMAIN_SCORE_H_ */
