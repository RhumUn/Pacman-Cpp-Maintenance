/*
 * OutFileStream.h
 *
 *  Created on: 31 oct. 2018
 *      Author: vicdo
 */

#ifndef FILESTREAM_OUTFILESTREAM_H_
#define FILESTREAM_OUTFILESTREAM_H_

#include <string>
#include <fstream>
#include <iostream>

class OutFileStream {
public:
	OutFileStream(std::string relativePath);
	virtual ~OutFileStream();
	void write(std::string content);
private:
	std::ofstream m_outFileStream;
};

#endif /* FILESTREAM_OUTFILESTREAM_H_ */
