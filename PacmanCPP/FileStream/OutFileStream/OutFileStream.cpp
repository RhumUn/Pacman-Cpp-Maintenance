#include "OutFileStream.h"
#include <fstream>
#include <iostream>
#include <string>

OutFileStream::OutFileStream(std::string relativePath) :
		m_outFileStream(relativePath, std::ios::app) {
}

void OutFileStream::write(std::string content) {
	try {
		if (this->m_outFileStream) {
			this->m_outFileStream << content << std::endl;
		} else {
			throw "Impossible d'écrire dans le fichier texte";
		}
	} catch (std::string const& error) {
		std::cerr << error << std::endl;
	}
}
