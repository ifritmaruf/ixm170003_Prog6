/*
 * Filename	example1.cc
 * Date 	04/29/20
 * Author	Ifrit Maruf
 * Email  	ixm170003@utdallas.edu
 * Course	CS 3377.501 Spring 2020
 * Version	1.0
 * Copyright	2020, All Rights Reserved
 *
 * Description
 * 	This file has the cdk file contents which references the referenced binary file
 * 	Uses the binary file to read header record from binary file.
 */

#include "program6.h"

void showMatrix(string matrix[MATRIX_HEIGHT + 1][MATRIX_WIDTH +1])
{
  //initialize variables for matrix screen
  WINDOW	*window;
  CDKSCREEN	*cdkscreen;
  CDKMATRIX     *myMatrix;           // CDK Screen Matrix

  const char 		*rowTitles[MATRIX_HEIGHT+1] = {"x", "a", "b", "c", "d", "e"};
  const char 		*columnTitles[MATRIX_WIDTH+1] = {"x", "a", "b", "c"};
  int		boxWidths[MATRIX_WIDTH+1] = {BOX_WIDTH, BOX_WIDTH, BOX_WIDTH, BOX_WIDTH};
  int		boxTypes[MATRIX_WIDTH+1] = {vMIXED, vMIXED, vMIXED, vMIXED};

  //Initialize the Cdk screen and make sure the putty terminal is large enough
  window = initscr();
  cdkscreen = initCDKScreen(window);

  //Start CDK Colors
  initCDKColor();

  //Create the matrix.  Need to manually cast (const char**) to (char **)
  myMatrix = newCDKMatrix(cdkscreen, CENTER, CENTER, MATRIX_HEIGHT, MATRIX_WIDTH, MATRIX_HEIGHT, MATRIX_WIDTH,
			  MATRIX_NAME_STRING, (char **) rowTitles, (char **) columnTitles, boxWidths,
				     boxTypes, 1, 1, ' ', ROW, true, true, false);
  //myMatrix doesnt having anything in there				     
  if (myMatrix ==NULL)
    {
      printf("Error, creating Matrix\n");
      exit(1);
    }

  //Display the Matrix
  drawCDKMatrix(myMatrix, true);
  int row;
  int col;
  for(row=1; row <= MATRIX_HEIGHT; row++){
   for(col=1; col <=  MATRIX_WIDTH + 1; col++){
    setCDKMatrixCell(myMatrix, row, col, matrix[row][col].c_str());
   }
  } 
  
  //required
  drawCDKMatrix(myMatrix, true);

  //Shows matrix for 5 seconds
  sleep (10);

  // Cleanup screen
  endCDK();
}

