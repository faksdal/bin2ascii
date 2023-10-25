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

		//cout << "Inside outer while, at the beginning" << endl;

		while((inputBuffer[totalCount] != ' ') && (totalCount <= (fileSize-2))){

			//cout << "Inside inner while " << endl;
			//cout << "inputBuffer[totalCount] " << inputBuffer[totalCount] << endl;
			//cout << "byteCount " << byteCount << endl;
			//cout << "Byte before shift: " << (char)byte << endl;
			//getchar();
			inputBuffer[totalCount] == '1' ? setBit(byte, byteCount) : clearBit(byte, byteCount);

			//cout << "Byte after shift: " << (char)byte;
			//getchar();

			totalCount++;
			byteCount--;
			/*
			cout << "byteCount " << byteCount << endl;
			//cout << "inputBuffer[totalCount] " << inputBuffer[totalCount] << endl;
			//cout << "fileSize-2 " << fileSize-2 << endl;

			inputBuffer[totalCount]? setBit(byte, byteCount): clearBit(byte, byteCount);
			cout << "Byte " << (char)byte << endl;

			//if(totalCount == (fileSize-2))
			//	break;

			totalCount++;
			byteCount++;
			//cout << "Press any key..." << endl;
			//getchar();
			*/

			/*
			cout << "byteCount " << byteCount << endl;
			cout << "totalCount " << totalCount << endl;
			cout << "inputBuffer[totalCount] " << inputBuffer[totalCount] << endl;
			byteCount++;

			*/
		}

		//while(inputBuffer[totalCount] == ' ')

		cout << (char)byte;

		totalCount++;
		byteCount	= 7;
		//cout << "Inside outer while, at the end" << endl;
		//cout << "Byte after shift: " << byte << endl;

		byte = 0;



		/*
		cout << "Byte " << byte << endl;
		byteCount = 0;
		byte = 0;

		*/
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

	inputBuffer.clear();
	inputBuffer += inputFile.get();
	//cout << "InputBuffer: " << inputBuffer << endl;

	while (inputFile.good()) {
		inputBuffer += inputFile.get();
		//cout << "InputBuffer: " << inputBuffer << endl;
	}
	inputFile.close();

	for(int i = 0; i <= fileSize-2; i++)
		//cout << "InputBuffer[" << i << "]: " << inputBuffer[i] << endl;

	//cout << "InputBuffer: " << inputBuffer << endl;
	if(verbose){
		cout << "Filesize " << fileSize << " bytes" << endl;
		//cout << "inputBuffer " << inputBuffer << endl;
		//cout << "inputBuffer[0] " << inputBuffer[0] << endl;
		//cout << "inputBuffer[fileSize-2] " << inputBuffer[fileSize-2] << endl;
		cout << "Done reading input file into buffer... " << endl;
	}

}



bin2ascii::bin2ascii(string _inputFileName, string _outputFileName, bool _verbose)
{
	inputFileName	= _inputFileName;
	outputFileName	= _outputFileName;

	verbose			= _verbose;

	if(verbose)
		cout << "Reading file " << inputFileName << ", writing results into " << outputFileName << "..." << endl;

	readInputFileIntoInputBuffer();
	parseInputBuffer();


}



bin2ascii::~bin2ascii()
{
	return;
}
