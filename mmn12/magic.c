#include <stdio.h>
#include <string.h>
#include "getter.c"
#include "tester.c"
#include "printer.c"
#include <math.h>

#define MAX_MATRIX 10
#define MIN_MATRIX 3
#define MAX_ARRAY_INPUT 100

int main(int argc, char *argv[])
{
	int numberOfSquare, sumOfSquare, isItMagicSquare;
	int square[MAX_MATRIX][MAX_MATRIX];
	int squareInputnumbers[MAX_ARRAY_INPUT];
	
	
	numberOfSquare = GetNumber();
	
	sumOfSquare = (int)( numberOfSquare * ((numberOfSquare * numberOfSquare) + 1) ) / 2;
	
	/* DEBUG */ 
	printf("sum is: %d\n", sumOfSquare);
	printf("square number is: %d\n\n", numberOfSquare);
	/* DEBUG */
	
	
  /* If square given is bigger than defined in this program */
	isSquareOutOfBounds(numberOfSquare, MAX_MATRIX, MIN_MATRIX);
	getSquareNumbers(squareInputnumbers);
	printArray(squareInputnumbers);
	testInputNumber(squareInputnumbers, numberOfSquare);
	/* Creates a square from input */ 
	printf("Square input number: %d\n", squareInputnumbers[0]);
	createSquare(square, numberOfSquare, squareInputnumbers);
	printSquare(square, numberOfSquare);
	isItMagicSquare = isItMagic(square, numberOfSquare); /* Checks if given rectangle is a square */
  printAnswer(isItMagicSquare, square, numberOfSquare);
  
	return 1;
}


