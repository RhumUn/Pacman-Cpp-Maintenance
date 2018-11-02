#include "InFileStream.h"
#include <fstream>
#include <iostream>
#include <string>

InFileStream::InFileStream(std::string relativePath) :
	m_inFileStream(relativePath) {
}

std::vector<std::string> InFileStream::readLineByLine() {
	try {
		if (this->m_inFileStream) {
			return this->read();
		}
		else {
			throw "Impossible de lire le fichier";
		}
	}
	catch (const char* error) {
		std::cerr << error << std::endl;
		std::vector<std::string> emptyVector;
		return emptyVector;
	}
}

std::vector<std::string> InFileStream::read() {
	std::string line;
	std::vector<std::string> fileInLines;

	while (std::getline(this->m_inFileStream, line)) {
		fileInLines.push_back(line);
	}

	return fileInLines;
}
