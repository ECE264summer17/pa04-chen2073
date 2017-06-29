#include <stdio.h>
#include <stdlib.h>
#include "answer04.h"


int main(int argc, char ** argv)
{

	int nrow, ncol;
	char ** maze, ** new_maze;
	
	int rrow, rcol;
	int wc;
	
	FILE * input = fopen(argv[1],"r");
	

	maze = Read_maze_from_2Dfile(input, &nrow, &ncol);
	wc = Write_maze_to_2Dfile(argv[2], maze, nrow, ncol);
	new_maze = Expand_maze_row(maze, nrow, ncol, &rrow, &rcol);
	
	Deallocate_maze_space(maze, nrow);
	Deallocate_maze_space(new_maze, rrow);

	fclose(input);
	

return 0;
}
