#include <stdio.h>
#include <string.h>
#include "mat.h"
#include "mat.c"

// mmn22.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include "mat.h"
#include "mat.c"


mat matArray[MAT_COUNT];
/*
Process inputs until recieving "stop".
matArray is an array containing MAT_A - MAT_F
*/
int main()
{
	char input[MAX_INPUT_LEN];
	do
	{
		printf("\nPlease enter a command: \n");
		scanf("%s", input);
		ProcessCommand(input);
	} while (strcmp(input, "stop") != 0);
	return 0;
}

/*Translates a command from the input to a function*/
void ProcessCommand(char command[])
{
	mat *mat1, *mat2, *mat3;
	float scalar;
	char c;
	if (strcmp(command, "stop") == 0)
		return;
	else if (strcmp(command, "read_mat") == 0)
	{
		read_mat();
	}
	else if (strcmp(command, "print_mat") == 0)
	{
		print_mat();
	}
	else if (strcmp(command, "add_mat") == 0)
	{
		mat1 = GetMatrixFromInput();
		mat2 = GetMatrixFromInput();
		mat3 = GetMatrixFromInput();
		if (mat1 && mat2 && mat3)
			add_mat(mat1, mat2, mat3);
	}
	else if (strcmp(command, "sub_mat") == 0)
	{
		mat1 = GetMatrixFromInput();
		mat2 = GetMatrixFromInput();
		mat3 = GetMatrixFromInput();
		if (mat1 && mat2 && mat3)
			sub_mat(mat1, mat2, mat3);
	}
	else if (strcmp(command, "mul_mat") == 0)
	{
		mat1 = GetMatrixFromInput();
		mat2 = GetMatrixFromInput();
		mat3 = GetMatrixFromInput();
		if (mat1 && mat2 && mat3)
			mul_mat(mat1, mat2, mat3);
	}
	else if (strcmp(command, "mul_scalar") == 0)
	{
		mat1 = GetMatrixFromInput();
		while (isspace(c = getchar()) || c == ',')
			;
		ungetc(c, stdin);
		if (scanf("%f", &scalar) != 1)
		{
			printf("Wrong parameters, second parameter must be a real number.\n");
			return;
		}
		mat2 = GetMatrixFromInput();
		if (mat1 && mat2)
			mul_scalar(mat1, scalar, mat2);
	}
	else if (strcmp(command, "trans_mat") == 0)
	{
		mat1 = GetMatrixFromInput();
		mat2 = GetMatrixFromInput();
		if (mat1 && mat2)
			trans_mat(mat1, mat2);
	}
	else
	{
		clearBuffer();
		printf("No such command...");
	}
}

/*
Checks if a matrix name can be fetched from the input, if so, return the corresponding matrix from the array
*/
mat* GetMatrixFromInput()
{
	char matrixName[6];
	char c;
	int matrixIndex;
	while (isspace(c = getchar()) || c == ',')
		;
	ungetc(c, stdin);
	scanf("%5s", matrixName);
	/* making sure nothing between matrix and command name + matrix name begins 'MAT_' */
	if (strncmp(matrixName, "MAT_", 4) != 0)
	{
		printf("ERROR: Wrong command syntax\n");
		clearBuffer();
		return 0;
	}
	if ((matrixIndex = (int)(matrixName[4] - 'A')) < MAT_COUNT)
		return &matArray[matrixIndex];
	printf("No such matrix name\n");
	clearBuffer();
	return 0;
}

/*
Reads a matrix from the input.
CCOL - Current column according to iterator.
CROW - Current row.
*/
void read_mat()
{
	mat *matrix;
	mat temp;
	int iterator = 0;
	int tempIndex = 0;
	char c;

	if ((matrix = GetMatrixFromInput()) == 0)
		return;


	while ((iterator < MAT_MEMBER_CNT) )
	{
		c = getchar();
		if (!isdigit(c) && c != EOF && c != '+' && c != '-' && c != ',' && !isspace(c) && c != '.')
		{
			printf("ERROR: read_mat got value other than number.\n");
			clearBuffer();
			return;
		}
		if (c == '\n' || c == 'EOF')
		{
			ungetc(c, stdin);
			clearBuffer();
			break;
		}
		ungetc(c, stdin);
		temp[CCOL][CROW] = get_number();
		iterator++;
	}

	for (; tempIndex < iterator; tempIndex++)
	{
		(*matrix)[TCOL][TROW] = temp[TCOL][TROW];
	}


	while (iterator < MAT_MEMBER_CNT)
	{
		(*matrix)[CCOL][CROW] = 0;
		iterator++;
	}

	/* provided more than 16 numbers */
	if ((c = getchar()) != EOF || c != '\n')
	{
		clearBuffer();
	}
}


float get_number()
{
	int sign;
	double currentNumber, isfloat;
	char c;

	while (isspace(c = getchar()) || c == ',')
		;


	isfloat = 0.0;
	sign = (c == '-') ? -1 : 1;
	if (c == '+' || c == '-')
	{
		c = getchar();
	}
	for (currentNumber = 0.0; isdigit(c) || c == '.'; c = getchar())
	{
		if (currentNumber == 0.0)
		{
			currentNumber = c - '0';
		}
		else if (isfloat == 0.0)
		{
			currentNumber = currentNumber * 10 + (c - '0');
		}
		else if (c == '.')
		{
			isfloat = 1.0;
		}
		else if (isfloat != 0.0)
		{
			isfloat *= 10.0;
			currentNumber += (c - '0') / isfloat;
		}
	}
	ungetc(c, stdin);
	currentNumber *= sign;
	return currentNumber;
}



/*
Prints a matrix,
*/
void print_mat()
{
	mat *matrix;
	const int decoratedMatSize = MATRIX_SIZE + 1;
	int iterator = 1;
	if ((matrix = GetMatrixFromInput()) == 0)
		return;
	while (iterator < decoratedMatSize*decoratedMatSize)
	{
		if (iterator < decoratedMatSize) /*First row*/
		{
			printf("\t%d", iterator - 1);
			if ((iterator%decoratedMatSize) == decoratedMatSize - 1)
				printf("\n");
		}
		else if ((iterator%decoratedMatSize) == 0) /*Row opener*/
			printf("%d", (iterator / decoratedMatSize) - 1);
		else /* regular cell / end of line*/
		{
			printf("\t%.2f", (*matrix)[(iterator%decoratedMatSize) - 1][(iterator / decoratedMatSize) - 1]);
			if ((iterator%decoratedMatSize) == decoratedMatSize - 1)
				printf("\n");
		}
		iterator++;
	}
}

void clearBuffer()
{
	char c;
	while ((c = getchar()) != '\n');
}


