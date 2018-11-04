#include "Score.h"

Score::Score() : m_score(0) {
}

int Score::getScore() {
	return this->m_score;
}

void Score::updateScore(int increment) {
	this->m_score += increment;
}

void Score::saveScore() {
	std::vector<std::string> vectorOf5BestScores = this->get5BestScores();

	if (this->isOneOf5BestScores(vectorOf5BestScores)) {
		OutFileStream stream("Score.txt");

		std::string contents(this->scoresContentsToSave(vectorOf5BestScores));

		stream.write(contents);
	}
}

std::string Score::getScoreInformationToString() {
	std::string scoreInformation;

	scoreInformation = "Votre score est de :" + std::to_string(this->m_score);
	scoreInformation += "\nVous avez realise ce niveau en " + std::to_string(this->m_timerInSeconds) + " secondes";

	scoreInformation += "\n\n";

	return scoreInformation;
}

std::string Score::get5BestScoresToString() {
	std::vector<std::string> vectorOf5BestScores = this->get5BestScores();

	std::string bestScoresInformation;

	bestScoresInformation += "Les 5 meilleurs scores sont les suivants :";

	for (int i = 0; i < 5; i++) {
		if (i < vectorOf5BestScores.size())
			bestScoresInformation += "\n  - " + vectorOf5BestScores[i];
		else
			bestScoresInformation += "\n  - Pas encore defini";
	}

	bestScoresInformation += "\n\n";

	return bestScoresInformation;
}

void Score::setTimer()
{
	Time timeAtEndOfGame;

	this->m_timerInSeconds = timeAtEndOfGame.getDiffWithPreviousTimeInSeconds(this->m_timeAtGameLaunch);
}

void Score::setFinalScore()
{
	int timeBonus(1);

	if (this->m_timerInSeconds < 35)
		timeBonus = 4;
	else if (this->m_timerInSeconds < 40)
		timeBonus = 3;
	else if (this->m_timerInSeconds < 45)
		timeBonus = 2;

	this->m_score *= timeBonus;
}

std::vector<std::string> Score::get5BestScores() {
	return InFileStream("Score.txt").readLineByLine();
}

bool Score::isOneOf5BestScores(std::vector<std::string> const& vectorOf5BestScores) {
	bool isOneOf5BestScores = false;

	if (vectorOf5BestScores.size() < 5 || this->getScoreValue(vectorOf5BestScores[4]) < this->m_score)
		isOneOf5BestScores = true;

	return isOneOf5BestScores;
}

int Score::getScoreValue(std::string scoreSavedInString) {
	std::size_t positionOfScoreValue = scoreSavedInString.find(": ");
	//+2 pour ignorer les caratères ": "
	std::string scoreValueInString = scoreSavedInString.substr(positionOfScoreValue + 2);

	return (int)std::stoi(scoreValueInString);
}

std::string Score::scoresContentsToSave(std::vector<std::string> vectorOf5BestScores) {
	std::string contents;
	bool currentScoreHasBeenWrited = false;
	int i(0);

	while (i < vectorOf5BestScores.size() && i < 4 && vectorOf5BestScores.size() != 0) {
		if (this->m_score > this->getScoreValue(vectorOf5BestScores[i]) && !currentScoreHasBeenWrited) {
			contents += this->scoreToStringForSaving() + "\n";
			currentScoreHasBeenWrited = true;
		}

		contents += vectorOf5BestScores[i] + "\n";

		i++;
	}

	if (!currentScoreHasBeenWrited)
		contents += this->scoreToStringForSaving();

	return contents;
}

std::string Score::scoreToStringForSaving() {
	Time time;
	return  time.getCurrentDateTimeToString() + ": " + std::to_string(this->m_score);
}


