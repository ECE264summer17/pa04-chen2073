This exercise will familiarize you with 2-dimensional arrays and
some more file operations.

# Learning Goals

1. To learn to create and manipulate 2-dimensional arrays using 
malloc function.
2. To learn to free the memory allocated
3. To learn to perform file operations

## Submitting Your Assignment 

You must submit one file:

1. answer04.c

In this exercise, you will write functions to:

1. To allocate space for store 2D array characters to represent a maze 
(1 point)
2. To free space allocated for the 2D maze (1 point)
3. Read a 2D maze in a multi-line file into a 2D array of characters (2 points)
4. Write a 2D maze from a 2D array of characters into a multi-line file (2 points)
5. Expand an n_rows x n_columns 2D maze into an (2n_rows-1) x n_columns 2D maze (3 points)

More details of the functions are provided below.

## Input file format 

In this exercise, we are concerned with only rectangular mazes,
which is made up of r rows and c columns.  Moreover, both r and c are
odd.  For example, the input file `maze7x9` which contains the following lines 
describes a maze with r = 7 and c = 9:

```
#####s###
#.......#
#.###.###
#.#.#...#
#.#.#####
#.......#
#####e###
```

Note that in the input file, it would contain exactly 7 lines.
Moreover, there is a newline character at the end of each line.
We number the rows from top to bottom as row 0 through row 6,
and the columns from left to right as column 0 through column 8.
This maze is contained in the file `maze7x9`.

You may assume that the file pointer contains a valid maze,
and that if a FILE pointer * fptr is passed as argument to the function,`it has already been successfully opened for read operations`. 
However, you may not assume that the file location indicator
is at the beginning of a file.  Also, you should not close a given
file pointer.  However, if you open another file in your function, you 
are responsible for closing that file.

We will use valgrind to make sure that you close all files
that you have opened and that the returned (char **) pointers (and the
other pieces of memory to which these pointers point directly or indirectly) 
are the only memory not yet freed.  Any other memory allocated in your
functions should be freed before you return from these functions.  We will 
also check that when we call the deallocation function, we can free 
these (char **) pointers and the other pieces of memory to which these 
pointers point directly or indirectly.  Failure to close a file you have opened
or failure of your deallocation function to free the memory for storing the 
mazes properly will result in a 40% penalty.

## Functions to be written 

The `first` function should allocate (using malloc) a 2 dimensional array 
of chars to store a nrow x ncol maze.  The array is made up of an array of
nrow (char *) pointers, each of which point to an array of 
ncol char's.   The function should return NULL if the allocation
is not successful.

The `second` function should free the space allocated by the first function.

The `third` function reads a nrow by ncol maze contained in a file and store
the valid characters in a maze into the 2D array.  Given a maze (of type 
char **), maze[i][j] should correspond to the character in row i and column
j of the maze.

The `fourth` function writes a nrow by ncol maze stored in a 2D array of
characters into a multi-line file (in the same format as the input file).
The returned value is the total number of characters written.  It should
correspond to the file size when you use "wc" command to do a word count.
If you have read a maze into a 2D array using the third function, and then
you write the 2D array into a file, the output file should be the same as
the input file.

The `fifth` function has to expand a nrow-by-ncol maze into a 
(2nrow-1)-by-ncol maze.  The first nrow rows of the new maze is
the same as the nrow-by-ncol maze.  The next (nrow-1) rows of
the new maze is a reflection of the first (nrow-1) rows of the 
new (and old) maze.  For this example, the expansion should yield
a maze shown below:

```
#####s###
#.......#
#.###.###
#.#.#...#
#.#.#####
#.......#
#####e###
#.......#
#.#.#####
#.#.#...#
#.###.###
#.......#
#####s###
```

The expanded maze can be found in the file `rows_expanded_maze7x9`.


# WARNINGS 

You will have to write a main function so that you can test these
five functions.  However, you SHOULD write the main function in
a separate file called pa04.c.  If you include the main function 
in answer04.c, we will not be able to compile your answer04.c,
and you will get zero for this exercise.  

The main function that the instructor will write also 
resides in pa04.c.  The following gcc command will be used for
compilation:

gcc -std=c99 -Wall -Werror -Wshadow -g -Wunreachable-code -Wvla pa04.c answer04.c -o pa04

If your code does not compile, you will get zero for this exercise.

You should write a Makefile to help you with the compilation. 

You cannot assume that the given file pointer will point at 
a particular location in the file.  If you do not set the file position
properly at the beginning of the function call, it is unlikely that you 
will pass any of our tests.  

Do not close the given file pointer in any of these functions.
You are responsible for closing any file pointer you have opened.
