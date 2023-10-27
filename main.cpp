/*
 * main.cpp
 *
 *  Created on: 21 Oct 2023
 *      Author: jole
 *
 *      Driver program for testing bin2ascii conversion
 *	Test text
 *
 *
 */
#include <iostream>
#include <iomanip>
#include <getopt.h>
#include <locale.h>

#include "bin2ascii.h"

using namespace std;



int main(int argc, char *argv[])
{
	bool	verbose = false, inputFileNameSet = false, outputFileNameSet = false, printToScreen = false;
	string	inputFileName;
	string	outputFileName;

	//
	//	getopt variables
	//
	int		c, optionIndex;



	//
	//	TODO Add proper switches as the projects goes along
	//
	char	*shortOptions = (char*)"i:o:vsh";
	struct option	longOptions[] = {
					{"input-file",	required_argument,	NULL,	'i'},
					{"output-file",	required_argument,	NULL,	'o'},
					{"verbose",		no_argument,		NULL,	'v'},
					{"help",		no_argument,		NULL,	'h'},
					//{"dow",		no_argument,		NULL,	'd'},
					{0, 0, 0, 0}
	};	//End of getopt()-variables

	//
	//	getopt() switch statement
	//
	//
	//
	while((c = getopt_long(argc, argv, shortOptions, longOptions, &optionIndex)) != -1){
		switch(c){
			case 'i':	{
							inputFileName		= optarg;
							inputFileNameSet	= true;

							//if(verbose)
							//	cout << "Verbose is true..." << endl;

							//bin2ascii b2a(inputFileName, outputFileName);
							break;
						}
			case 'o':	{
							outputFileName		= optarg;
							outputFileNameSet	= true;

							//if(verbose)
							//	cout << "Verbose is true..." << endl;

							break;
						}

			case 'v':	{
							verbose = true;
							break;
						}
			case 's':	{
							printToScreen = true;
							cout << "Printing to screen..." << endl;
							break;
						}
			case 'h':	{
							//printUsage();
							cout << "Add some useful information on how to use this software..." << endl;
							exit(1);
						}
			default:	{
							cout << "Switch default" << endl;
							break;
						}
		}	//end of getopt() switch statement
	}	// end of while-loop

	if(!inputFileNameSet){
			cout << "You need to specify input file..." << endl << "Use --help for help" << endl;;
			exit(-1);
	}
	if(!outputFileNameSet){
		//cout << "main.cpp: Setting output filename to default..." << endl;
		outputFileName = "bin2ascii_default_output.txt";
	}

	//cout << "main.cpp: Inputfile: " << inputFileName << ", outputfile: " << outputFileName << endl;

	bin2ascii b2a(inputFileName, outputFileName, verbose, printToScreen);

	//cout << "Finished converting " << inputFileName << " to " << outputFileName << endl;

	//cout << "main.cpp: after bin2ascii b2a(inputFileName, outputFileName, verbose);" << endl;

	return 0;
}	//	int main(int argc, char *argv[])
