#include "Time.h"
#include <string>
#include <time.h>
#include <iostream>

Time::Time() {}

std::string Time::getCurrentTime() {
	// current date/time based on current system
	time_t now;
	struct tm timeinfo;
	time(&now);
	localtime_s(&timeinfo, &now);

	std::string timeToString;

	timeToString += Time::formatTMStructure(timeinfo.tm_mday) + "/";
	timeToString += Time::formatTMStructure(1 + timeinfo.tm_mon) + "/";
	timeToString += Time::formatTMStructure(1900 + timeinfo.tm_year) + " ";
	timeToString += Time::formatTMStructure(timeinfo.tm_hour) + ":";
	timeToString += Time::formatTMStructure(timeinfo.tm_min) + ":";
	timeToString += Time::formatTMStructure(timeinfo.tm_sec);

	return timeToString;
}

std::string Time::formatTMStructure(int tmStruct) {
	std::string tmStructureFormatted = std::to_string(tmStruct);

	tmStructureFormatted = tmStructureFormatted.size() == 1 ? "0" + tmStructureFormatted : tmStructureFormatted;

	return tmStructureFormatted;
}