/*
 * Filename	binMain.cc
 * Date		04/29/20
 * Author	Ifrit Maruf
 * Email	ixm170003@utdallas.edu
 * Course	CS 3377.501 Spring 2020
 * Version	1.0
 * Copyright	2020, All Rights Reserved
 *
 * Description
 * 	This file opens the references bin file and uses it to create 
 *	the cdk matrix by using the headers in program6.h
 *
 */

#include "program6.h"

int main(){

//Open the bin file
ifstream file("/scratch/perkins/cs3377.bin", ios::in | ios::binary);

//Initialize Matrix
string matrix[MATRIX_HEIGHT + 1][MATRIX_WIDTH +1];

//if file doesnt open
if(!file.is_open())
{
 cerr << "Error, file failed to open correctly" << endl;
 exit(1);
} 
else
{
 //Create header using BinaryFileHeader()
 BinaryFileHeader *header= new BinaryFileHeader();

 //Check
 if(!file.read((char *) header, sizeof(BinaryFileHeader)))
 {
  cerr << "Error, reading the file" << endl;
  exit(1);
 }

 //Create to read in the first row
 stringstream firstRow;

 firstRow << "Versions: " << header->versionNumber;
 cerr << header->versionNumber;
 matrix[1][2] = firstRow.str();
 firstRow.str("");
 firstRow.clear();

 firstRow << "NumRecords: " << header->numRecords;
 matrix[1][3] = firstRow.str();
 firstRow.str("");
 firstRow.clear();

 firstRow << "Magic: 0x" << hex << uppercase <<  header->magicNumber;
 matrix[1][1] = firstRow.str();
 firstRow.str("");
 firstRow.clear();

 //Create to get the rest of the records
 stringstream recordStream;

 BinaryFileRecord *record= new BinaryFileRecord();

 uint64_t numRecords;
 if(header->numRecords < 4)
 {
 numRecords= header->numRecords;
 }
 else
 {
 numRecords=4;
 }

 for(uint64_t i=2; i <numRecords + 2; i++)
 {

 //check to see no errors and that there is a record
 if(!file.read((char *) record, sizeof(BinaryFileRecord)))
 {
    cerr << "Error in reading for the records" << endl;
    exit(1);
 }

 //Store into matrix for each row starting at 2 after the headers
 recordStream << "strlen: " << (int) record->strLength;
 matrix[i][1] = recordStream.str();
 matrix[i][2] = record->stringBuffer;
 recordStream.str("");
 recordStream.clear();
}

 //Call function to display matrix referencing binary file
 showMatrix(matrix);

 //Close .bin file
 file.close();

 } //end else

//End program
return 0;
}


