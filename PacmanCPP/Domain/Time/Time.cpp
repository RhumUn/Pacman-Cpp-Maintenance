#include "Time.h"

Time::Time() {
	time(&this->m_dateTime);
	localtime_s(&this->m_timeStructure, &this->m_dateTime);
}

time_t Time::getDateTime() {
	return this->m_dateTime;
}

int Time::getDiffWithPreviousTimeInSeconds(Time previousTime) {
	time_t previousDateTime = previousTime.getDateTime();
	return (int)difftime(this->m_dateTime,previousDateTime);
}

std::string Time::getCurrentDateTimeToString() {
	std::string timeToString;

	timeToString += this->formatTMStructure(this->m_timeStructure.tm_mday) + "/";
	timeToString += this->formatTMStructure(1 + this->m_timeStructure.tm_mon) + "/";
	timeToString += this->formatTMStructure(1900 + this->m_timeStructure.tm_year) + " ";
	timeToString += this->formatTMStructure(this->m_timeStructure.tm_hour) + ":";
	timeToString += this->formatTMStructure(this->m_timeStructure.tm_min) + ":";
	timeToString += this->formatTMStructure(this->m_timeStructure.tm_sec);

	return timeToString;
}

std::string Time::formatTMStructure(int tmStruct) {
	std::string tmStructureFormatted = std::to_string(tmStruct);

	tmStructureFormatted = tmStructureFormatted.size() == 1 ? "0" + tmStructureFormatted : tmStructureFormatted;

	return tmStructureFormatted;
}