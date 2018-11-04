#ifndef FILESTREAM_INFILESTREAM_H_
#define FILESTREAM_INFILESTREAM_H_

#include <string>
#include <fstream>
#include <iostream>
#include <vector>

class InFileStream
{
public:
	InFileStream(std::string relativePath);

	std::vector<std::string> readLineByLine();

private:
	std::ifstream  m_inFileStream;

	std::vector<std::string> read();
};

#endif /* FILESTREAM_INFILESTREAM_H_ */
