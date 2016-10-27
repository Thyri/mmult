// // // // // // // // // // // // // //
/// File: mmult-driver.c
/// Description: The main file for project 2 in Mechanics of Programming
/// @author: Max Maurin <csci243>
// // // // // // // // // // // // // //
#include "mmult.h"
#include <stdio.h>
#include <stdlib.h>

int main(int argc, char *argv[]){

	int number_of_matrices = 0;
	char input[MAXLINE];

	int state_flag = -1;
	int rows = 0;
	int cols = 0;
	int *dimensions;

	int curpos = 1;

	while(fgets(input, MAXLINE, stdin)){
		if (state_flag == -1){
			number_of_matrices = atoi(input);
			state_flag = 0;
			printf("There are %d matrices\n", number_of_matrices);

		}
		else if (state_flag == 0){
			dimensions = get_dimensions(input);
			rows = dimensions[0];
			cols = dimensions[1];
			printf("Matrix #%d Was found:\n", curpos++);
			printf("	It has %d rows\n", rows);
			printf("	it has %d cols\n", cols);
			printf("\n\n");
			state_flag = rows;
		}
		else if (state_flag >= 0){
			state_flag = state_flag - 1;
			continue;
		}
	}

	return 0;
}
