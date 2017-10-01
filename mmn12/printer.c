
void Greeting()
{
	printf("Welcome to Magic Square program!\n");
	printf("Please, enter magic square numbers.\n");
}

void printSquare(int square[MAX_MATRIX][MAX_MATRIX], int squareSize)
{
	int i, j;
	printf("Provided Square:\n");
	for(i = 0; i < squareSize; i++)
	{
		for(j = 0; j < squareSize; j++)
		{
			printf("%6d\t", square[i][j]);
		}
		printf("\n");
	}
}


void printAnswer(int isItMagicSquare, int square[MAX_MATRIX][MAX_MATRIX], 
									int squareSize)
	{
		printf("\n\n");
		printSquare(square, squareSize);
		if(isItMagicSquare == 1)
		{
			printf("Is a Magic Square!");
		}
		else
		{
			printf("Is not Magic Square!");
		}
	}
