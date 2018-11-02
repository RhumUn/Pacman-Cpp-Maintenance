#ifndef TIME_TIME_H_
#define TIME_TIME_H_

#include <string>

class Time
{
public:
	Time();
	std::string getCurrentTime();
private:
	std::string formatTMStructure(int tmStruct);
};

#endif /* TIME_TIME_H_ */