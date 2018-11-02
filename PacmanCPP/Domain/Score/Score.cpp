#include "Score.h"
#include "../../FileStream/OutFileStream/OutFileStream.h"
#include "../../FileStream//InFileStream/InFileStream.h"
#include <string>
#include <iostream>


Score::Score() : m_score(0) {
}

int Score::getScore() {
	return this->m_score;
}

void Score::updateScore(int increment) {
	this->m_score += increment;
}

void Score::saveScore() {
	std::vector<std::string> vectorOf5BestScores = Score::get5BestScores();

	if (Score::isOneOf5BestScores(vectorOf5BestScores)) {
		OutFileStream stream("Score.txt");

		std::string contents(Score::scoresContentsToSave(vectorOf5BestScores));

		stream.write(contents);
	}
}

std::vector<std::string> Score::get5BestScores() {
	return InFileStream("Score.txt").readLineByLine();
}

bool Score::isOneOf5BestScores(std::vector<std::string> const& vectorOf5BestScores) {
	bool isOneOf5BestScores = false;

	if (vectorOf5BestScores.size() < 5 || Score::getScoreValue(vectorOf5BestScores[4]) < this->m_score)
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
		if (this->m_score > Score::getScoreValue(vectorOf5BestScores[i]) && !currentScoreHasBeenWrited) {
			contents += Score::toString() + "\n";
			currentScoreHasBeenWrited = true;
		}

		contents += vectorOf5BestScores[i] + "\n";

		i++;
	}

	if (!currentScoreHasBeenWrited)
		contents += Score::toString();

	return contents;
}

std::string Score::toString() {
	return "Date du jour 1: " + std::to_string(this->m_score);
}

