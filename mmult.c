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
	return 0;
}

// Dynamically allocate an r x c matrix of doubles, initialized to zeros.
//r = Rows in the matrix
//c = columns in the matrix
//returns: matrix:  a pointer to an array of rows, which are actually just pointers
//	to arrays of columns.
double **xalloc(int r, int c){
	int **matrix = (int **)malloc(r * sizeof(int *));
	int i = 0;
	for (i=0; i<r; i++){
		matrix[i] = (int *)malloc(c * sizeof(int));
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
double **mread(FILE *fp, int *r, int *c){
	return 0;
}

// writes the rAxcA matrix A to already open file
void mwrite(FILE *fp, int rA, int cA, double **A){
	return;
}

// return the element of A at the r-th row and c-th column
double aref(int r, int c, double **A){
	return A[r-1][c-1];
}

// set the value of the element of A at the r-th row and c-th column to x
void aset(int r, int c, double **A, double x){
	A[r-1][c-1] = x;
	return;
}

// Return the number of Matrices specified in the input file
long get_count(){
	return 0;
}

// Determine the dimensions of the matrix specified in the input file
long get_dimensions(){
	return 0;
}

// Fill The Matrix allocated at memory Address N with values from the input file
void fill_matrix(){
	return;
}

// Print a readable output for the matrix multiplication
void print_matrix(){
	return;
}

