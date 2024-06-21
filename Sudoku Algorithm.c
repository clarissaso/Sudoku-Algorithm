/* Program to assist in the challenge of solving sudoku puzzles.

   Skeleton program written by Alistair Moffat, ammoffat@unimelb.edu.au,
   August 2021, with the intention that it be modified by students
   to add functionality, as required by the assignment specification.

*/

#include <stdio.h>
#include <stdlib.h>
#include <assert.h>

/* these #defines provided as part of the initial skeleton */

#define NDIM 3		/* sudoku dimension, size of each inner square */
#define NDIG (NDIM*NDIM)
			/* total number of values in each row */
#define NGRP 3		/* number of sets each cell is a member of */
#define NSET (NGRP*NDIG)
			/* total number of sets in the sudoku */
#define NCLL (NDIG*NDIG)
			/* total number of cells in the sudoku */

#define ERROR	(-1)	/* error return value from some functions */

/* these global constant arrays provided as part of the initial skeleton,
   you may use them in your code but must not alter them in any way,
   regard them as being completely fixed. They describe the relationships
   between the cells in the sudoku and provide a basis for all of the
   sudoku processing loops */

/* there are 27 different different sets of elements that need to be
   checked against each other, this array converts set numbers to cells,
   that's why its called s2c */
int s2c[NSET][NDIM*NDIM] = {
	/* the first group of nine sets describe the sudoku's rows */
	{  0,  1,  2,  3,  4,  5,  6,  7,  8 },
	{  9, 10, 11, 12, 13, 14, 15, 16, 17 },
	{ 18, 19, 20, 21, 22, 23, 24, 25, 26 },
	{ 27, 28, 29, 30, 31, 32, 33, 34, 35 },
	{ 36, 37, 38, 39, 40, 41, 42, 43, 44 },
	{ 45, 46, 47, 48, 49, 50, 51, 52, 53 },
	{ 54, 55, 56, 57, 58, 59, 60, 61, 62 },
	{ 63, 64, 65, 66, 67, 68, 69, 70, 71 },
	{ 72, 73, 74, 75, 76, 77, 78, 79, 80 },
	/* the second group of nine sets describes the sudoku's columns */
	{  0,  9, 18, 27, 36, 45, 54, 63, 72 },
	{  1, 10, 19, 28, 37, 46, 55, 64, 73 },
	{  2, 11, 20, 29, 38, 47, 56, 65, 74 },
	{  3, 12, 21, 30, 39, 48, 57, 66, 75 },
	{  4, 13, 22, 31, 40, 49, 58, 67, 76 },
	{  5, 14, 23, 32, 41, 50, 59, 68, 77 },
	{  6, 15, 24, 33, 42, 51, 60, 69, 78 },
	{  7, 16, 25, 34, 43, 52, 61, 70, 79 },
	{  8, 17, 26, 35, 44, 53, 62, 71, 80 },
	/* the last group of nine sets describes the inner squares */
	{  0,  1,  2,  9, 10, 11, 18, 19, 20 },
	{  3,  4,  5, 12, 13, 14, 21, 22, 23 },
	{  6,  7,  8, 15, 16, 17, 24, 25, 26 },
	{ 27, 28, 29, 36, 37, 38, 45, 46, 47 },
	{ 30, 31, 32, 39, 40, 41, 48, 49, 50 },
	{ 33, 34, 35, 42, 43, 44, 51, 52, 53 },
	{ 54, 55, 56, 63, 64, 65, 72, 73, 74 },
	{ 57, 58, 59, 66, 67, 68, 75, 76, 77 },
	{ 60, 61, 62, 69, 70, 71, 78, 79, 80 },
};


/* there are 81 cells in a dimension-3 sudoku, and each cell is a
   member of three sets, this array gets filled by the function 
   fill_c2s(), based on the defined contents of the array s2c[][] */
int c2s[NCLL][NGRP];

void
fill_c2s() {
	int s=0, d=0, c;
	for ( ; s<NSET; s++) {
		/* record the first set number each cell is part of */
		for (c=0; c<NDIM*NDIM; c++) {
			c2s[s2c[s][c]][d] = s;
		}
		if ((s+1)%(NGRP*NDIM) == 0) {
			d++;
		}
	}
#if 0
	/* this code available here if you want to see the array
	   cs2[][] that gets created, just change that 0 two lines back
	   to a 1 and recompile */
	for (c=0; c<NCLL; c++) {
		printf("cell %2d: sets ", c);
		for (s=0; s<NGRP; s++) {
			printf("%3d", c2s[c][s]);
		}
		printf("\n");
	}
	printf("\n");
#endif
	return;
}

/* find the row number a cell is in, counting from 1
*/
int
rownum(int c) {
	return 1 + (c/(NDIM*NDIM));
}

/* find the column number a cell is in, counting from 1
*/
int
colnum(int c) {
	return 1 + (c%(NDIM*NDIM));
}

/* find the minor square number a cell is in, counting from 1
*/
int
sqrnum(int c) {
	return 1 + 3*(c/NSET) + (c/NDIM)%NDIM;
}

/* If you wish to add further #defines, put them below this comment,
   then prototypes for the functions that you add

   The only thing you should alter above this line is to complete the
   Authorship Declaration 
*/


/****************************************************************/

/* Function prototypes */
typedef int sudoku_t[NCLL];

int read_sudoku(sudoku_t input);
void print_sudoku(sudoku_t input, int unknown);
void check_grid(sudoku_t input, int s2c[NSET][NDIG], sudoku_t error_set);
void print_error(sudoku_t error_set, int num_error);
int strategy_1(sudoku_t input, int s2c[NSET][NDIG], int c2s[NCLL][NGRP], 
	sudoku_t input_upd, int unknown);
void repeat_s1(sudoku_t input, int s2c[NSET][NDIG], int c2s[NCLL][NGRP], 
	sudoku_t input_upd, int unknown);
void sdk_swap(sudoku_t input, sudoku_t input_upd);
void print_unknown(int unknown);
void print_tadaa(int unknown);

/****************************************************************/

/* main program controls all the action
*/
int
main(int argc, char *argv[]) {
	int input[NCLL], input_upd[NCLL], error_set[NSET], unknown;
	
	fill_c2s();
	
	unknown = read_sudoku(input);
	print_sudoku(input, unknown);
	
	check_grid(input, s2c, error_set);
	repeat_s1(input, s2c, c2s, input_upd, unknown);
	
	/* all done, so pack up bat and ball and head home */
	return 0;
}

/****************************************************************/

/* Read numbers in the input data and store them in an array.
   Count and return the total of unknown cells. */
int 
read_sudoku(sudoku_t input) {
	int cell;
	int unknown = 0;
	
	for (cell = 0; cell < NCLL; cell++) {
        scanf("%1d", &input[cell]);
        if (!input[cell]) {
        	unknown++;
        }
    }
    return unknown;
}

/****************************************************************/

/* Print a neatly-formatted sudoku representation of the input data */
void
print_sudoku(sudoku_t input, int unknown) {
    int cell = 1;
    
    printf("\n");
    
    /* Loop considers one cell at a time */
    while (cell <= NCLL) {
    	/* Add space before the numbers, except numbers on the first column */
    	if ((cell-1) % 9) {
			printf(" ");
		} 
    	
		if (!input[cell - 1]) {
			/* Number unknown */
    		printf(".");
    	} else {
    		/* Number known */
			printf("%d", input[cell - 1]);
		} 
		
		if (!(cell % 27) && cell < NCLL) {
			/* After three rows */
			printf("\n------+-------+------\n");  
		} else if (!(cell % 9)) {
			/* After a row */
			printf("\n");
		} else if (!(cell % 3)) {    
			/* Between three numbers */
			printf(" |");
		} 
        cell++;  
    }
    print_unknown(unknown);
    return;
}

/****************************************************************/

/* Check the input grid for sudoku errors, then print out the errors and 
   the total violations if existed */
void 
check_grid(sudoku_t input, int s2c[NSET][NDIG], sudoku_t error_set) {
	int num, elem, cell, count, row, col, sqr;
	int set = 0;
    int status = 0;
    int num_error = 0;
    	
	/* Loop considers one set at a time */
	while (set < NSET) {
		
		/* Iterate for all possible numbers in sudoku */
		for (num = 1; num <= NDIG; num++) { 
			count = 0;
			
			/* Count the occurence of number in each set */
			for (elem = 0; elem < NDIG; elem++) {
				cell = s2c[set][elem];
				if (input[cell] == num) {
					count++;
				} 
			}
			
			/* Detect and print error when number occurs more than once in a 
			   set */
			if (count > 1) {
				status = ERROR;
				error_set[num_error] = set;
				num_error++;
				if (set < 9) { 
					/* Error in the row set */
					row = set + 1;
					printf("\nset %2d (row %d): %d instances of %d", set, 
						row, count, num);
				} else if (set < 18) {
					/* Error in the column set */
					col = set - 8;
					printf("\nset %2d (col %d): %d instances of %d", set, 
						col, count, num);
				} else {
					/* Error in the square set */
					sqr = set - 17;
					printf("\nset %2d (sqr %d): %d instances of %d", set, 
						sqr, count, num);
				}
				
			}
			
		}
		
		set++;	
	}
	
	/* Print the violations */
	if (status) {
		print_error(error_set, num_error);
	}
	return;
}

/****************************************************************/

/* Implement strategy one.
   Return the total of cells that can be solved. */
int 
strategy_1(sudoku_t input, int s2c[NSET][NDIG], int c2s[NCLL][NGRP], 
	sudoku_t input_upd, int unknown) {
	int num, count, stop, th_set, elem, set, set_elem, saved, ans, i;
	int row[NCLL], col[NCLL], new[NCLL];
	int cell = 0;
	int solved = 0;
	int j = 0;
	
	/* Loop considers one cell at a time */
	while (cell < NCLL) {
		if (!input[cell]) {
			saved = 0;
			
			/* Iterate for all possible numbers in sudoku */
			for (num = 1; num <= NDIG; num++) {
				count = 0;
				stop = 0;
				
				/* Iterate for all sets contained in a cell */
				for (th_set=0; th_set < NGRP && !stop; th_set++) {
					
					/* Iterate for all cells in a set */
					for (elem=0; elem < NDIG; elem++) {
						set = c2s[cell][th_set];
						set_elem = s2c[set][elem];
						/* Continue to next number when number is detected in 
						   the set */
						if (input[set_elem] == num) {
							count = 0;
							stop = ERROR;
							break;
						} 
						count++;				
					}
					
				}
				
				/* Number that passes through all iterations */
				if (count == NSET) {
					if (!saved) {
						/* Only one possible answer */
						ans = 1;
						saved = num;	
					} else if (saved) {
						/* More than one possible answer */
						ans = 0;
					}
				}
				
			}
			
			/* Update the sudoku cell */
			if (ans) {
				/* Use the number when it is the only possible answer */
				solved++;
				input_upd[cell] = saved;
				row[j] = c2s[cell][0] + 1;
				col[j] = c2s[cell][1] - 8;
				new[j] = input_upd[cell];
				j++;
			} else {
				/* Use zero when there is more than one possible answer */
				input_upd[cell] = 0;
			}
			
		} else {
			/* Transfer the input data to the updated sudoku cells */
			input_upd[cell] = input[cell];
		}
		cell++;
	}
	
	/* Print solved cells after scanning through the sudoku once */
	if (solved) {
		printf("\nstrategy one\n");
		for (i = 0; i < j; i++) {
			printf("row %d col %d must be %d\n", row[i], 
				col[i], new[i]);
		}
	}
	return solved;
}

/****************************************************************/

/* Repeat strategy one until no more cells can be solved */
void
repeat_s1(sudoku_t input, int s2c[NSET][NDIG], int c2s[NCLL][NGRP], 
	sudoku_t input_upd, int unknown) {
	int solved = 1;
	
	while (solved) {
		solved = strategy_1(input, s2c, c2s, input_upd, unknown);
		sdk_swap(input, input_upd);
		unknown-=solved;
	}
	
	/* Print the updated sudoku after final implementation of strategy one */
	print_sudoku(input, unknown);
	print_tadaa(unknown);	
	return;
}

/****************************************************************/

/* Swap every elements in the two arrays */	
void 
sdk_swap(sudoku_t input, sudoku_t input_upd) {
	int cell, tmp;
	
	for (cell = 0; cell < NCLL; cell++) {
		tmp = input[cell];
		input[cell] = input_upd[cell];
		input_upd[cell] = tmp;
	}skel
	return;
}

/****************************************************************/

/* Count and print the total violations when error is detected, then 
   exit the program. */
void 
print_error(sudoku_t error_set, int num_error) {
	int i;
	int viol = 1;
	
	for (i = 1; i < num_error; i++) {
		if (error_set[i] != error_set[i - 1]) {
		viol++;
		}
	}
	printf("\n\n%d different sets have violations\n", viol);
	printf("%d violations in total\n", num_error);
	exit(EXIT_SUCCESS); 
	return;
}

/* Other helper functions */

void
print_unknown(int unknown) {
	printf("\n");
	if (!unknown) {
		printf(" ");
	}
	printf("%d cells are unknown\n", unknown);
	return;
}

void
print_tadaa(int unknown) {
	if (!unknown) {
		printf("\nta daa!!!\n");
	}
	return;
}

/****************************************************************/

/* algorithms are fun */	
