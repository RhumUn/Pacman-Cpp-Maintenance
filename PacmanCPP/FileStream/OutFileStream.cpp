/*
 * OutFileStream.cpp
 *
 *  Created on: 31 oct. 2018
 *      Author: vicdo
 */

#include "OutFileStream.h"
#include <fstream>
#include <iostream>
#include <string>

OutFileStream::OutFileStream(std::string relativePath) :
		m_outFileStream(relativePath, std::ios::app) {
}

OutFileStream::~OutFileStream() {
	// TODO Auto-generated destructor stub
}

void OutFileStream::write(std::string content) {
	try {
		if (OutFileStream::m_outFileStream) {
			OutFileStream::m_outFileStream << content << std::endl;
		} else {
			throw "Impossible d'écrire dans le fichier texte";
		}
	} catch (std::string const& error) {
		std::cerr << error << std::endl;
	}
}
