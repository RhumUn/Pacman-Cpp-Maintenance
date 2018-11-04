#ifndef TIME_TIME_H_
#define TIME_TIME_H_

#include <string>
#include <time.h>
#include <iostream>

class Time
{
public:
	Time();

	time_t getDateTime();

	int getDiffWithPreviousTimeInSeconds(Time);

	std::string getCurrentDateTimeToString();

private:
	std::string formatTMStructure(int tmStruct);

	time_t m_dateTime;

	struct tm m_timeStructure;
};

#endif /* TIME_TIME_H_ */