/*
 * Usage of CDK Matrix
 *
 * File:   example1.cc
 * Author: Stephen Perkins
 * Email:  stephen.perkins@utdallas.edu
 */

#include <iostream>
#include "cdk.h"


#define MATRIX_WIDTH 5
#define MATRIX_HEIGHT 3
#define BOX_WIDTH 15
#define MATRIX_NAME_STRING "Matrix Program 6"

using namespace std;

int main()
{

  WINDOW	*window;
  CDKSCREEN	*cdkscreen;
  CDKMATRIX     *myMatrix;           // CDK Screen Matrix

  const char 		*rowTitles[MATRIX_HEIGHT+1] = {"0", "a", "b", "c"};
  const char 		*columnTitles[MATRIX_WIDTH+1] = {"0", "a", "b", "c", "d", "e"};
  int		boxWidths[MATRIX_WIDTH+1] = {BOX_WIDTH, BOX_WIDTH, BOX_WIDTH, BOX_WIDTH};
  int		boxTypes[MATRIX_WIDTH+1] = {vMIXED, vMIXED, vMIXED, vMIXED};

  /*
   * Initialize the Cdk screen.
   *
   * Make sure the putty terminal is large enough
   */
  window = initscr();
  cdkscreen = initCDKScreen(window);

  /* Start CDK Colors */
  initCDKColor();

  /*
   * Create the matrix.  Need to manually cast (const char**) to (char **)
  */
  myMatrix = newCDKMatrix(cdkscreen, CENTER, CENTER, MATRIX_WIDTH, MATRIX_HEIGHT, MATRIX_WIDTH, MATRIX_HEIGHT,
			  MATRIX_NAME_STRING, (char **) columnTitles, (char **) rowTitles, boxWidths,
				     boxTypes, 1, 1, ' ', ROW, true, true, false);

  if (myMatrix ==NULL)
    {
      printf("Error creating Matrix\n");
      _exit(1);
    }

  /* Display the Matrix */
  drawCDKMatrix(myMatrix, true);

  //Set whats in the matrix
  setCDKMatrixCell(myMatrix, 1, 1, "Magic: 0xFEEDFACE");
  setCDKMatrixCell(myMatrix, 1, 2, "Versions: 16");
  setCDKMatrixCell(myMatrix, 1, 3, "NumRecords: 4");
  setCDKMatrixCell(myMatrix, 2, 1, "strlen: 10 ");
  setCDKMatrixCell(myMatrix, 2, 2, "Seed Money");
  setCDKMatrixCell(myMatrix, 3, 1, "strlen: 10");
  setCDKMatrixCell(myMatrix, 3, 2, "Leadership");
  setCDKMatrixCell(myMatrix, 4, 1, "strlen: 10");
  setCDKMatrixCell(myMatrix, 4, 2, "Entrepreneurship");
  setCDKMatrixCell(myMatrix, 5, 1, "strlen: 6");
  setCDKMatrixCell(myMatrix, 5, 2, "Skillz");

  drawCDKMatrix(myMatrix, true);    /* required  */

  /* so we can see results */
  sleep (10);

  // Cleanup screen
  endCDK();
}
