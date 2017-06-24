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
   return NULL;
}

// free the memory used for the maze
// you may assume that maze is not NULL, and all memory addresses are valid

void Deallocate_maze_space(char **maze, int nrow) 
{
   return;
}

#endif /* NTEST_MEM */

#ifndef NTEST_READ

/* Read maze in a multi-line file into a 2D array of characters */
/* you may assume that the maze has odd row and column counts */

char **Read_maze_from_2Dfile(FILE *fptr, int *nrow, int *ncol)
{
   *nrow = *ncol = 0;
   return NULL;
}

#endif /* NTEST_READ */

#ifndef NTEST_WRITE

/* Write maze in a 2D array of characters into a multi-line file */
/* you may assume that the maze has odd row and column counts */

int Write_maze_to_2Dfile(char *filename, char **maze, int nrow, int ncol) 
{
   return -1;
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
   return NULL;
}

#endif /* NTEST_ROW */

// if you want to declare and define new functions, put them here
// or at the beginning of the file
