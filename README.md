# Sudoku-Algorithm

**Sudoku!**
The goal of sudoku is to complete a square grid of 9×9 = 81 cells using only the numbers from 1 to 9, in a way that has exactly one instance of each digit appearing in each column, in each row, and in each 3 × 3 sub-square. For example, in Figure 1 the cell marked with the red circle must be a “7”, since every other possible value appears in at least one of the three sets (row, purple; column, blue; and sub-square, green) that cell is a member of. All of the other cells in the example can be determined using the same strategy.

Your task in this assignment is to develop a sudoku assistant, to help people solve their sudoku puzzles. You will
use a one-dimensional C array to store a linearized version of the sudoku matrix (see Figure 4), and will write functions that carry out useful operations, including checking for numbering violations, identifying any “it must be that value” cells, and perhaps even solving some easy puzzles through to completion.

Start by copying the skeleton program ass1-skel.c and sample data file data1.txt from the LMS Assignment 1 page, and check that you can compile the program via either grok or gcc. Note that if you plan to use grok, you will need to learn how to execute programs in grok via the “terminal” interface that it provides. There is a handout linked from the LMS that provides guidance.

The skeleton file provides an empty main program that includes a very important authorship dec- laration. Substantial mark penalties apply if you do not include it in your submission, or do not sign it. The skeleton program also includes two very useful pre-filled “constant” matrices. Make sure that you understand their roles, described below (and in more detail in the Assignment 1 video). Those global matrices are intended to be constant, and you should not change their values in any way.

![page1image14459216](https://github.com/clarissaso/Sudoku-Algorithm/assets/80309625/8b4de7c9-ca68-4278-b96b-0939c4f5612e)
Figure 1: An "Easy" sudoku.

**Stage 1 – Reading and Printing**
The input to your program will always be a set of 81 one-digit numbers, laid out as a sudoku grid, and with “0” used to represent empty cells. For example, the sudoku in Figure 1 is represented in the test file data1.txt in the manner shown on the left of Figure 2. You should read the input using a sequence of 81 calls (in a loop, of course) to scanf("%d", &val), to avoid the need to deal with blank and newline characters.

You are encouraged to use a one-dimensional array of 81 values in your program, rather than a 9 × 9 two-dimensional array; and to map the sudoku grid into that array in row-major order, as shown in Figure 4. Using a one-dimensional arrangement allows you to employ single-nested loops instead of always needing double loops, and to make use of the constant arrays that are part of the skeleton program: c2s[] (cell-to-set) has eighty-one rows and three columns, with c2s[c] listing the ordinal numbers of the three sets that include c; and s2c[] (set-to-cell) has twenty-seven rows and nine columns, with s2c[s] listing the cells that make up set number s. For example, in Figure 4 cell number 51 is a member of set number 5 (a row-based set); of set number 15 (a column-based set); and of set number 23 (a square-based set). That means that the three elements in c2s[51] will be 5, 15, and 23. In the inverse mapping, s2c[15] contains the nine cells in set 15, namely 6, 15, 24, 33, 42, 51, 60, 69, and 78. You’ll need to be able to manipulate these two arrays in Stage 2 and Stage 3.

![Screen Shot 2024-06-22 at 00 20 03](https://github.com/clarissaso/Sudoku-Algorithm/assets/80309625/90ae8909-7743-4cf1-8d93-91c43c7bd559)
Figure 2: Input data1.txt (left); corresponding Stage 1 output (center); input data2.txt (right).

The required output from a Stage 1 program is a neatly-formatted representation of the input data, plus a summary line, see the center part of Figure 2. Note that “%NDIM” and “%NDIG” and %(NDIM*NDIG) operations can be used to identify places where formatting is required to output the required grid.

**Stage 2 – Grid Checking**
Extend your program so that it checks the input grid for mistakes, to ensure that none of the 27 sets in the supplied puzzle have duplicate elements. Report any errors according to their set number, from 0 to 26, and also by the set type (“row”, “col”, or “sqr”) and the ordinal (counting from one) number of that set. For example, on the (incorrect) input file data2.txt (see the right side of Figure 2), the Stage 2 output must be as shown in Figure 3. Other examples are available on the LMS. If any errors are detected in the input, your program should exit once it has printed out its Stage 2 diagnostic messages.

![Screen Shot 2024-06-22 at 00 22 10](https://github.com/clarissaso/Sudoku-Algorithm/assets/80309625/d73df600-8f67-489d-912a-1593e1d00d95)
Figure 3: Stage 2 output (data2.txt).


