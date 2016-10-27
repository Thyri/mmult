// // // // // // // // // // // // // //
/// File: mmult-driver.c
/// Description: The main file for project 2 in Mechanics of Programming
/// @author: Max Maurin <csci243>
// // // // // // // // // // // // // //
#include "mmult.h"
#include <stdio.h>
#include <stdlib.h>

int main(int argc, char *argv[]){
	int rA = 2;
	int rB = 3;
	int cA = 3;
	int cB = 2;

	double **A = xalloc(rA, cA);
	double **B = xalloc(rB, cB);

	aset(1,1,A,1.00);
	aset(2,2,A,1.00);

	aset(1,1,B,2.00);
	aset(1,2,B,1.00);
	aset(2,1,B,2.00);
	aset(2,2,B,2.00);
	aset(3,1,B,1.00);
	aset(3,2,B,2.00);


	print_Matrix(rA, cA, A);
	printf("\n\n");
	print_Matrix(rB, cB, B);
	printf("\n\n");

	double **C = NULL;
	C = mmult(rA, cA, A, rB, cB, B);

	print_Matrix(rA, cB, C);
//	printf("%.2f\n", aref(1,1,C));
	printf("\n\n");
	return 0;
}
