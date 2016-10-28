// // // // // // // // // // // // // //
/// File: mmult.c
/// Description: helper functions for project 2
/// @author: Max Maurin <csci243>
// // // // // // // // // // // // // //

#include "mmult.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Return the product A*B as a new, dynamically allocated rA x cB matrix.
//rA = Rows in matrix A
//cA = Columns in matrix A
//**A = Matrix A
//
//rB = Rows in matrix B
//cB = Columns in matrix B
//**B = Matrix B
//
//returns **mmult: A new matrix C of size (rA x cB), requires xalloc.
double **mmult(int rA, int cA, double **A, int rB, int cB, double **B){
	double **result = xalloc(rA, cB);
	int i = 0; //to be compared to rA
	int j = 0; //to be compared to cB
	int k = 0; //to be compared to cA/rB (These should be the same)
	int sum = 0;

	for (i = 0; i < rA; i++){
		for (j = 0; j < cB; j ++){
			for (k = 0; k < cA; k++){
				sum = sum + A[i][k]*B[k][j];
			}
			result[i][j] = sum;
			sum = 0;
		}
	}
	return result;
}

// Dynamically allocate an r x c matrix of doubles, initialized to zeros.
//r = Rows in the matrix
//c = columns in the matrix
//returns: matrix:  a pointer to an array of rows, which are actually just pointers
//	to arrays of columns.
double **xalloc(int r, int c){
	double **matrix = (double **)malloc(r * sizeof(double *));
	int i = 0;
	for (i=0; i<r; i++){
		matrix[i] = (double *)malloc(c * sizeof(double));
	}
	return matrix;
}

// Free all memory allocated for A
//r = Rows in the matrix
//c = columns in the matrix
void xfree(int r, int c, double **A){
	int i = 0;

	for (i=0; i<r; ++i) {
		free(A[i]);
	}
	free(A);

	return;
}

// reads a matrix (in row-major order) from file
double **mread(FILE *fp, int r, int c){
	double **arr = xalloc(r, c);
	float num = 0;
	int i = 0;
	int j = 0;

	for (i = 0; i < r; i++){
		for (j = 0; j < c; j++){
			fscanf(fp, "%f", &num);
			arr[i][j] = (double) num;
		}
	}
	return arr;
}

// writes the rAxcA matrix A to already open file
//void mwrite(FILE *fp, int rA, int cA, double **A){
//	return;
//}

// return the element of A at the r-th row and c-th column
// Matrix notation would have A[0][0] be represented by A(1,1)
//      to account for this, we subtract 1 from r and c to convert from
//      matrix notation to array notation
double aref(int r, int c, double **A){
	return A[r-1][c-1];
}

// set the value of the element of A at the r-th row and c-th column to x
// Matrix notation would have A[0][0] be represented by A(1,1)
//	to account for this, we subtract 1 from r and c to convert from
//	matrix notation to array notation
void aset(int r, int c, double **A, double x){
	A[r-1][c-1] = x;
	return;
}

// print out the contents of a matrix
void print_Matrix(int r, int c, double **A){
	int i =0;
	int j = 0;

	for (i = 0; i <  r; i++){
		for (j = 0; j < c; j++){
			printf("%.2f     ", A[i][j]);
		}
		printf("\n");
	}

	return;
}

// When the main function determines that it needs the dimensions
// for the next array, this function is called on the next line of
// input.
//
//returns: array, an array of size 2 that contains the ints [rows, cols]
int *get_dimensions(char *input){
	int i = 0;
	char *p = strtok (input, " ");
	int *array = (int *)malloc(2 * sizeof(int));

	int placeholder = 0;

	while (p != NULL)
	{
		placeholder = atoi(p);
		array[i++] = placeholder;
		p = strtok (NULL, " ");
	}

	return array;
}
