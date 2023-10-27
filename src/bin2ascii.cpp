/*
 * bin2ascii.cpp
 *
 *  Created on: 21 Oct 2023
 *      Author: jole
 */

#include <chrono>
#include "bin2ascii.h"



void bin2ascii::parseInputBuffer(void)
{
	int		totalCount, byteCount;
	//short	byte = 0;
	char	character = ' ';
	//bool	invalidValueEncountered = false;

	//
	//	initialize totalCount to 0
	//	keep track of this, comparing it to fileSize to avoid trying to access beyond end of inputString
	//
	totalCount	= 0;

	//	we read inputBuffer from left-to-right meaning the first bit we read is the 7th (the leftmost in the byte)
	//	each succeeding bit is  lower in value
	//
	//	|7|6|5|4|3|2|1|0|
	//
	byteCount	= 7;

	if(verbose){
		cout << "Parsing";
	}

	/*
	 *
	 *	TODO  rewrite the parsing routine
	 *
	 *	What I want from the parse:
	 *		- if the read value is 1, set the corresponding bit
	 *		- else clear the corresponding bit
	 *		- keep track of how many bits read
	 *		- keep track of the total count so we don't go beyond end of inputBuffer
	 *		- if we encounter other values than 0's and 1's, skip to the next
	 *
	 */


	//
	//	let's start with a loop...
	//
	while((totalCount <= (fileSize-2))){

		switch(inputBuffer[totalCount]){
			case '0':	{
							clearBit(character, byteCount);
							totalCount++;
							byteCount--;
							//cout << "clearBit" << endl;
							break;
						}
			case '1':	{
							setBit(character, byteCount);
							totalCount++;
							byteCount--;
							//cout << "setBit" << endl;
							break;
						}
			default:	{
							totalCount++;
							//cout << "default" << endl;
							break;
						}
		}	// switch(inputBuffer[totalCount])

		if(verbose){
			cout << ".";

		}


		if(byteCount < 0){
			outputBuffer += character;
			byteCount = 7;
		}


	}	// while((totalCount <= (fileSize-2)))

	cout << endl;
	cout << endl << outputBuffer << endl;
}



void bin2ascii::readInputFileIntoInputBuffer(void)
{
	inputFile.open(inputFileName, std::ifstream::in);

	if(inputFile.fail()){
		cout << "Inputfile " << inputFileName << " does not exist!" << endl;
		fileExist = false;
		return;
	}

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
	fileExist		= true;

	inputFileName	= _inputFileName;
	outputFileName	= _outputFileName;

	verbose			= _verbose;
	printToScreen	= _printToScreen;

	inputBuffer.clear();
	outputBuffer.clear();

	if(verbose)
		cout << "Reading file " << inputFileName << ", writing results into " << outputFileName << "..." << endl;


	readInputFileIntoInputBuffer();

	if(fileExist)
		parseInputBuffer();
	else
		return;


}



bin2ascii::~bin2ascii()
{
	return;
}
