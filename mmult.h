// // // // // // // // // // // // // //
/// File: mmult.h
/// Description: header file for all
//	helper functions in mmult.c
/// @author: Max Maurin <csci243>
// // // // // // // // // // // // // //

#ifndef MMULT_H
#define MMULT_H
#define NUL     '\0'
#define MAXLINE 80
// Return the product A*B as a new, dynamically allocated rA x cB matrix.
double **mmult(int rA, int cA, double **A, int rB, int cB, double **B);

// Dynamically allocate an r x c matrix of doubles, initialized to zeros.
double **xalloc(int r, int c);

// Free all memory allocated for A
void xfree(int r, int c, double **A);

// reads a matrix (in row-major order) from file
//double **mread(FILE *fp, int *r, int *c);

// writes the rAxcA matrix A to already open file
//void mwrite(FILE *fp, int rA, int cA, double **A);

// return the element of A at the r-th row and c-th column
double aref(int r, int c, double **A);

// set the value of the element of A at the r-th row and c-th column to x
void aset(int r, int c, double **A, double x);

// print out the contents of a matrix
void print_Matrix(int r, int c, double **A);

// determine the dimensions of a matrix
int *get_dimensions(char *input);
#endif
