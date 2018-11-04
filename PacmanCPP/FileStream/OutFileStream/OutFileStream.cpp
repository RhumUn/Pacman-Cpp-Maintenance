#include "OutFileStream.h"

OutFileStream::OutFileStream(std::string relativePath) :
	m_outFileStream(relativePath) {
}

void OutFileStream::write(std::string content) {
	try {
		if (this->m_outFileStream) {
			this->m_outFileStream << content;
		}
		else {
			throw "Impossible d'écrire dans le fichier texte";
		}
	}
	catch (std::string const& error) {
		std::cerr << error << std::endl;
	}
}
