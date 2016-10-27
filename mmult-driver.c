// // // // // // // // // // // // // //
/// File: mmult-driver.c
/// Description: The main file for project 2 in Mechanics of Programming
/// @author: Max Maurin <csci243>
// // // // // // // // // // // // // //
#include "mmult.h"
#include <stdio.h>
#include <stdlib.h>

int main(int argc, char *argv[]){
	int r = 2;
	int c = 3;

	double **A = xalloc(r, c);
	print_Matrix(r,c,A);
	printf("setting (1,1) to 15.5\n");
	aset(1,1,A,15.5);
	print_Matrix(r,c,A);
	printf("aref of (1,1) returned: %f \n", aref(1,1,A));
	xfree(r,c,A);
	print_Matrix(r,c,A);
	return 0;
}
