//  CS 302 Provided Main

#include <iostream>
#include <iomanip>
#include <string>
#include <fstream>
#include <unistd.h>

#include "huffman.h"

using namespace std;

// *****************************************************************

int main(int argc, char *argv[])
{

// ---------------------------------------
//  Headers...

	string	bars, stars;
	bars.append(65, '-');
	stars.append(65, '*');
	string	inputFile="";
	int	sLen=0;

	cout << bars << endl << "CS 302 - Assignment #10, "
			<< "File Compression" << endl;
	cout << endl;

// ---------------------------------------
//  Read and verify command line arguments.

	if (argc == 1) {
		cout << "Usage: compress -f <inputFile>" << endl;
		return 0;
	}

	if (argc != 3) {
		cout << "Error, invalid command line options." << endl;
		return	0;
	}


	if (string(argv[1]) != "-f") {
		cout << "Error, invalid file name specifier." << endl;
		return	0;
	}

	if (access(argv[2], F_OK) == -1) {
		cout << "compress: Error, input file does not exist." << endl;
		return	0;
	}

	inputFile = string(argv[2]);
	sLen = inputFile.length();

	if (sLen < 5) {
		cout << "compress: Error, input file name not valid." << endl;
		return	0;
	}

	if (inputFile.substr(sLen-4, sLen) != ".txt") {
		cout << "compress: Error, must provided text file (.txt)." << endl;
		return	0;
	}

// ---------------------------------------
//  Perform compression pass.
//	Does not peform compression.
//	Determines compression approach and estimated percentage.

	huffman		myData;

	if (!myData.checkCompression(inputFile))
		cout << "Error, can not read input file." << endl;

// ---------------------------------------
//  All done, end program.

	cout << stars << endl << "Game Over, thank you for playing." << endl;

	return 0;
}

