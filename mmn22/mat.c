#include <stdio.h>


/*
CCOL - Current Column
CROW - Current Row

Add and Sub work in the same way, they iterate over the cells and assign the value of the operation on mat A and mat B to mat C.
*/
void add_mat(mat* A, mat* B, mat* C)
{
	int iterator;
	printf("-----adding matrixes-----\n");
	for (iterator = 0; iterator < MAT_MEMBER_CNT; iterator++)
	{
		(*C)[CCOL][CROW] = (*A)[CCOL][CROW] + (*B)[CCOL][CROW];
	}
}

void sub_mat(mat* A, mat* B, mat* C)
{
	int iterator;
	printf("-----subtracting matrixes-----\n");
	for (iterator = 0; iterator < MAT_MEMBER_CNT; iterator++)
		(*C)[CCOL][CROW] = (*A)[CCOL][CROW] - (*B)[CCOL][CROW];
}

/*
Iterates the same way as add and sub, only for each cell in C iterate and calculate the sum of the cell's row in A and the cell's column in B.
*/
void mul_mat(mat* A, mat* B, mat* C)
{
	int iterator, mulIterator;
	printf("-----multiplying matrixes-----\n");
	for (iterator = 0; iterator < MAT_MEMBER_CNT; iterator++)
	{
		(*C)[CCOL][CROW] = 0;
		mulIterator=0;
		for (mulIterator=0; mulIterator < MATRIX_SIZE; mulIterator++)
			(*C)[CCOL][CROW] += (*A)[mulIterator][CROW] * (*B)[CCOL][mulIterator];
	}
}

void mul_scalar(mat* A, float scalar, mat* B)
{
	int iterator;
	printf("-----multiplying matrix by scalar-----\n");
	for (iterator = 0; iterator < MAT_MEMBER_CNT; iterator++)
	{
		(*B)[CCOL][CROW] = (*A)[CCOL][CROW] * scalar;
	}
}

void trans_mat(mat* A, mat* B)
{
	int iterator;
	printf("-----tranposing matrix-----\n");
	for (iterator = 0; iterator < MAT_MEMBER_CNT; iterator++)
	{
		(*B)[CCOL][CROW] = (*A)[CROW][CCOL];
	}
}