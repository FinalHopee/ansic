#define MAX_MATRIX 10
#define MIN_MATRIX 3
#define MAX_ARRAY_INPUT 100
#define ASCII_CHAR_TO_DIGIT 48

/* tester.c*/
void isSquareOutOfBounds(int squareSize, int maxMatrix, int minMatrix);

int isItMagic(int square[MAX_MATRIX][MAX_MATRIX], int squareSize, int sumOfSquare);

int comp (const void * elem1, const void * elem2);

void testInputNumber(int squareInputnumbers[], int squareSize);

void createSquare(int square[MAX_MATRIX][MAX_MATRIX], int squareSize, 	int *squareInputnumbers);


/* printer.c */
void Greeting();

void printSquare(int square[MAX_MATRIX][MAX_MATRIX], int squareSize);

void printAnswer(int isItMagicSquare, int square[MAX_MATRIX][MAX_MATRIX], int squareSize);


/* getter.c */
int GetNumber();

void getSquareNumbers(int squareInputnumbers[]);
