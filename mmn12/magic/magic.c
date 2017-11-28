#include <stdio.h>
#include <string.h>
#include <math.h>
#include "getter.c"
#include "tester.c"
#include "printer.c"
#include "magic.h"


int main(int argc, char *argv[])
{
	int numberOfSquare, sumOfSquare, isItMagicSquare;
	int square[MAX_MATRIX][MAX_MATRIX];
	int squareInputnumbers[MAX_ARRAY_INPUT];
	
	
	numberOfSquare = GetNumber();
	/* Calculating the magic sum which is the sum of row or a column */
	sumOfSquare = (int)( numberOfSquare * ((numberOfSquare * numberOfSquare) + 1) ) / 2;
	
	
  /* If square given is bigger than defined in this program */
	isSquareOutOfBounds(numberOfSquare, MAX_MATRIX, MIN_MATRIX);
	getSquareNumbers(squareInputnumbers);
	testInputNumber(squareInputnumbers, numberOfSquare);
	/* Creates a square from input */ 
	createSquare(square, numberOfSquare, squareInputnumbers);
	/* Checks if given rectangle is a square */
	isItMagicSquare = isItMagic(square, numberOfSquare, sumOfSquare); 
  printAnswer(isItMagicSquare, square, numberOfSquare);
  
	return 1;
}


