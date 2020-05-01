/*
 * Filename		program6.h
 * Date			04/29/20
 * Author		Ifrit Maruf
 * Email		ixm170003@utdallas.edu
 * Course		CS 3377.501 Spring 2020
 * Version		1.0
 * Copyright		2020, All Right Reserved
 *
 * Description		
 * 	This file includes all the #includes, #defines, class structs,
 * 	and prototypes
 *
 */

#ifndef PROGRAM6_H
#define PROGRAM6_H

#include <iostream>
#include <sstream>
#include <fstream>
#include <string>
#include <stdint.h>
#include <cstring>
#include <cstdlib>	//exit()
#include <stdio.h>
#include <stdlib.h>
#include "cdk.h"

#define MATRIX_HEIGHT 5
#define MATRIX_WIDTH 3
#define BOX_WIDTH 20
#define MATRIX_NAME_STRING "Binary File Contents"

using namespace std;

//Header Record
class BinaryFileHeader
{
 public: 
 	uint32_t magicNumber;
	uint32_t versionNumber;
	uint64_t numRecords;
};

const int maxRecordStringLength = 25;

//Data Record
class BinaryFileRecord
{
 public:
 	uint8_t strLength;
	char	stringBuffer[maxRecordStringLength];
};

//2nd cc file function
void showMatrix(string [MATRIX_HEIGHT+ 1][MATRIX_WIDTH+1]);
#endif
