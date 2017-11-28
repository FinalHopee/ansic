#include <stdlib.h>


#define MAX_MATRIX 10
#define MAX_ARRAY_INPUT 100
#define MIN_MATRIX 3
#define ASCII_CHAR_TO_DIGIT 48

/*
 * Gets a number from input 
 * Tests if it is integer number, gives error output on error and exits with -1.
 */
int GetNumber()
{
	int number;
	char c;
	number = -1;
	
	while((c = getchar()) != EOF)
	{
		if (c >= '0' && c <= '9')
		{
			if (number != -1) /* Two digits numbers go here */
			{
				number = (number * 10) + c - ASCII_CHAR_TO_DIGIT;
			}
			else /* First time, one digit number*/
			{
				number = c - ASCII_CHAR_TO_DIGIT;
			}
		}
		else if (c == ' ' || c == '\n' || c == '\t' || c == '\v' ||\
		         c == '\f' || c == '\r')
		{
			if (number == -1) /* white spaces between numbers */
			{
			  continue;
			}
			else
			{
				return number;
			}
		} /* end else if */
		else /* Not numbers */
		{
			printf("ERROR: Wrong input! Must be integer numbers only!\n\n");
			exit(-1); /* exit program with error */
		}
	}
	
	return number;
}

/* 
 * Creates 2-D array representing a square
 
void createSquare(int square[MAX_MATRIX][MAX_MATRIX])
{
	int num, indexSquareNumbers;
	 define array for input 
	int inputSquareArray[MAX_ARRAY_INPUT];
	
	while(indexSquareNumbers < MAX_ARRAY_INPUT)
	{
		GetNumber();
		
		
		
	}
	
		*/
	/* Tests if number read is in range 1 - N^2
	 * isNumInRange(num);
	 *  
	
	
	
	
	
	
}*/

/* 
 * Sets input to Array of integers
 */
void getSquareNumbers(int squareInputnumbers[])
{
	int i;
	for(i = 0; i < MAX_ARRAY_INPUT; i++)
	{
		squareInputnumbers[i] = GetNumber();
	}
}

void printArray(int squareInputnumbers[])
{
	int i;
	for(i = 0; i < MAX_ARRAY_INPUT; i++)
	{
		printf("%d ",squareInputnumbers[i]);
	}
	printf("\n\n");
}
