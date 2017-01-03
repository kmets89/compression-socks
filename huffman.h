/* Kaylan Mettus
 * CS302-1002
 * Assignment 10
 * 
 * The header file for the huffman class */
 
#ifndef HUFFMAN_H
#define HUFFMAN_H
 
#include <iostream>
#include <fstream>
#include <cmath>
#include "priorityQueue.h"
 
class huffman {
public:
	//constructor
	huffman();
	//reads in characters from a file and builds a huffman tree using
	// a priority queue
	bool checkCompression(const std::string);
private:	 
	struct hNode {
		char ch;
		int count;
		hNode *left;
		hNode *right;
	};
	static const int SIZE = 256;
	int counts[SIZE];
	std::string strCodes[SIZE];
	std::string bits;
	//builds a huffman tree from a priority queue
	void buildTree();
	//creates compression codes for each character in the tree
	void makeCodes(hNode *, std::string);
	//prints the huffman tree
	void printTree(hNode *);
	//prints the codes for each character
	void printCodes();
	//prints difference in bits before and after compression
	void showStats(int);
};
 
#endif
