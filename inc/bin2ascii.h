/*
 *	bin2ascii.h
 *
 * 	Created on: 21 Oct 2023
 *	Author: jole
 *
 *	Look into C++ bitset in #include <bitset>
 *	https://owlcation.com/stem/C-bitset-with-example
 *
 *
 *
 */

#ifndef __BIN2ASCII_H__
#define __BIN2ASCII_H__

#include <fstream>
#include <iostream>
#include <cstdint>

using namespace std;


#define setBit(byte, bitNumber)		((byte) |=  (1 << (bitNumber)))
#define clearBit(byte,bitNumber)	((byte) &= ~(1 << (bitNumber)))
#define flipBit(byte,bitNumber)		((byte) ^=  (1 << (bitNumber)))
#define checkBit(byte,bitNumber)	((byte) &   (1 << (bitNumber)))



class bin2ascii {

	int			fileSize;

	bool		verbose, printToScreen, fileExist;

	string		inputFileName;
	string		outputFileName;
	string		inputBuffer, outputBuffer;
	ifstream	inputFile;
	ofstream	outputFile;

	void	readInputFileIntoInputBuffer(void);
	void	parseInputBuffer(void);

public:
	bin2ascii(string _inputFileName, string _outputFileName, bool _verbose, bool _printToScreen);
	~bin2ascii();

};

#endif /* __BIN2ASCII_H__ */



