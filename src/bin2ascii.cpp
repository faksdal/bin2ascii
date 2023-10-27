/*
 * bin2ascii.cpp
 *
 *  Created on: 21 Oct 2023
 *      Author: jole
 */

#include "bin2ascii.h"



void bin2ascii::parseInputBuffer(void)
{
	int		totalCount, byteCount;
	short	byte = 0;

	totalCount	= 0;
	byteCount	= 7;

	if(verbose){
		cout << "Parsing input buffer..." << endl;

		cout << "fileSize " << fileSize << endl;
		cout << "inputBuffer " << inputBuffer << endl;
	}

	while(totalCount <= (fileSize-2)){

		while((inputBuffer[totalCount] != ' ') && (totalCount <= (fileSize-2))){

			//cout << "inputBuffer[totalCount] " << inputBuffer[totalCount] << endl;

			inputBuffer[totalCount] == '1' ? setBit(byte, byteCount) : clearBit(byte, byteCount);

			totalCount++;
			byteCount--;
		}

		cout << (char)byte;

		totalCount++;
		byteCount	= 7;
		byte = 0;
	}

	cout << endl;

}



void bin2ascii::readInputFileIntoInputBuffer(void)
{
	inputFile.open(inputFileName, std::ifstream::in);

	// seek to end of file to get the size
	inputFile.seekg(0, ios::end);
	fileSize = inputFile.tellg();

	// return fp to beginning of file
	inputFile.seekg(0, ios::beg);

	inputBuffer += inputFile.get();
	//cout << "InputBuffer: " << inputBuffer << endl;

	while (inputFile.good()) {
		inputBuffer += inputFile.get();
		//cout << "InputBuffer: " << inputBuffer << endl;
	}
	inputFile.close();

	if(verbose){
		cout << "Filesize " << fileSize << " bytes" << endl;
		//cout << "inputBuffer " << inputBuffer << endl;
		//cout << "inputBuffer[0] " << inputBuffer[0] << endl;
		//cout << "inputBuffer[fileSize-2] " << inputBuffer[fileSize-2] << endl;
		cout << "Done reading input file into buffer... " << endl;
	}

}



bin2ascii::bin2ascii(string _inputFileName, string _outputFileName, bool _verbose, bool _printToScreen)
{
	inputFileName	= _inputFileName;
	outputFileName	= _outputFileName;

	verbose			= _verbose;
	printToScreen	= _printToScreen;

	inputBuffer.clear();
	outputBuffer.clear();

	if(verbose)
		cout << "Reading file " << inputFileName << ", writing results into " << outputFileName << "..." << endl;

	readInputFileIntoInputBuffer();
	parseInputBuffer();


}



bin2ascii::~bin2ascii()
{
	return;
}
