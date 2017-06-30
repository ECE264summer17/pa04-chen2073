#include <stdio.h>
#include <stdlib.h>
#include "answer04.h"

// if you want to declare and define new functions, put them here
// or at the end of the file


// do not remove #ifndef and #endif in this file, otherwise the evaluation
// would fail and you would definitely get 0
// any new functions you want to create and use in this file 
// should appear above these comments or at the end of this file

#ifndef NTEST_MEM

// allocate space for nrow x ncol maze, if allocation fails, return NULL
// if allocation fails, you are also responsible for freeing the memory
// allocated before the failure
// may assume that nrow and ncol are > 0

char **Allocate_maze_space(int nrow, int ncol)
{
	char ** arry = (char**) calloc(nrow,  sizeof(char*));

	if(arry == NULL){
		return NULL;
	}
	
	
	for(int i=0; i< nrow; i++){
		arry[i] = (char*) calloc(ncol, sizeof(char));
	}
	
	return arry;

}

// free the memory used for the maze
// you may assume that maze is not NULL, and all memory addresses are valid

void Deallocate_maze_space(char **maze, int nrow) 
{
	int i;
	
	for(i=0; i < nrow; i++){
	free(maze[i]);}

	free(maze);
   
}

#endif /* NTEST_MEM */

#ifndef NTEST_READ

/* Read maze in a multi-line file into a 2D array of characters */
/* you may assume that the maze has odd row and column counts */

char **Read_maze_from_2Dfile(FILE *fptr, int *nrow, int *ncol)
{
   *nrow = *ncol = 0;

	char ** maze;
	
	fseek(fptr, 0, SEEK_SET);

	int f = fgetc(fptr);

	while(f != EOF){
		if(f == '\n'){
			(*nrow)++;
		}
		else if (*nrow == 0){
			(*ncol)++;
		}
	f = fgetc(fptr);
	}

	printf("row %d, col %d\n", *nrow, *ncol);
	//int length = ftell(fptr);
	//(*ncol) = ((length - *nrow) / (*nrow));

	maze = Allocate_maze_space(*nrow, *ncol);

	fseek(fptr, 0, SEEK_SET);

	int i, j;

	//f = 0;

	for(i=0; i < *nrow; i++){
	    for (j=0; j <= *ncol; j++){	
		int k = fgetc(fptr);
		if(k != '\n'){
		   	maze[i][j] = k;}
		//	printf("%c", maze[i][j]);

	     }
	}
//	printf("\n");
	return maze;
}

#endif /* NTEST_READ */

#ifndef NTEST_WRITE

/* Write maze in a 2D array of characters into a multi-line file */
/* you may assume that the maze has odd row and column counts */

int Write_maze_to_2Dfile(char *filename, char **maze, int nrow, int ncol) 
{

	FILE * fp = fopen(filename, "w");

	if(fp == NULL){
	return -1;}

	int i, j;

	for(i=0; i < nrow; i++){

		for(j=0; j < ncol; j++){

		fputc(maze[i][j], fp);}

	fputc('\n', fp);
	}

	fclose(fp);

   return (i * (j+1)); 
}

#endif /* NTEST_WRITE */

#ifndef NTEST_ROW

/* Expand the maze from nrow x ncol to (2nrow - 1) x ncol */
/* the top half of the maze is the same as the original maze */
/* the bottom half of the maze is a reflection of the original maze */
/* *rrow and *rcol have to be updated with the new row and column counts */
/* You have to create a new maze */
/* if you can't expand the maze because of memory issue, NULL should be */
/* returned, and both *rrow and *rcol set to 0 */
/* the original maze has to stay intact */
/* you may assume that the original maze has odd row and column counts */

char **Expand_maze_row(char **maze, int nrow, int ncol, int *rrow, int *rcol)
{
   *rrow = *rcol = 0;
   
	char ** new_maze;

	*rrow = (2 * nrow) - 1;
	*rcol = ncol;

	new_maze = Allocate_maze_space(*rrow, *rcol);

	int i, j;

	/*for(i=0; i < (*nrrow); i++){

		for(j=0; j < (*rcol); j++){
	
			if( (i+1) * (j+1) == sizeof(maze) ){             //check end of maze
			new_maze[i][j] = maze[(*rrow+1) - i][j];}   

			new_maze[i][j] = maze[i][j];
		}
	}*/

	for(i=0; i < nrow; i++){

		for(j=0; j < ncol; j++){

			new_maze[i][j] = maze[i][j];
		}
	}
	int k=2;
	for(i=nrow; i < *rrow; i++){

		for(j=0; j < *rcol; j++){

			new_maze[i][j] = maze[nrow - k][j];
		}
	k++;
	}



/*	for(i=0; i < *rrow; i++){
		 for(j=0; j < *rcol; j++){
			printf("%c", new_maze[i][j]);
		}
	printf("\n");
	}
	printf("\n"); */

	return new_maze;
}

#endif /* NTEST_ROW */

// if you want to declare and define new functions, put them here
// or at the beginning of the file
