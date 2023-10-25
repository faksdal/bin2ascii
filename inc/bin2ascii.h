/*
 * bin2ascii.h
 *
 *  Created on: 21 Oct 2023
 *      Author: jole
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

	bool		verbose;

	string		inputFileName;
	string		outputFileName;
	string		inputBuffer;
	ifstream	inputFile;
	ofstream	outputFile;

	void	readInputFileIntoInputBuffer(void);
	void	parseInputBuffer(void);

public:
	bin2ascii(string _inputFileName, string _outputFileName, bool _verbose);
	~bin2ascii();

};

#endif /* __BIN2ASCII_H__ */
