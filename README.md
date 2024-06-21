# Sudoku-Algorithm

**Sudoku!**
The goal of sudoku is to complete a square grid of 9×9 = 81 cells using only the numbers from 1 to 9, in a way that has exactly one instance of each digit appearing in each column, in each row, and in each 3 × 3 sub-square. For example, in Figure 1 the cell marked with the red circle must be a “7”, since every other possible value appears in at least one of the three sets (row, purple; column, blue; and sub-square, green) that cell is a member of. All of the other cells in the example can be determined using the same strategy.
Your task in this assignment is to develop a sudoku assistant, to help people solve their sudoku puzzles. You will
use a one-dimensional C array to store a linearized version of the sudoku matrix (see Figure 4), and will write functions that carry out useful operations, including checking for numbering violations, identifying any “it must be that value” cells, and perhaps even solving some easy puzzles through to completion.
Start by copying the skeleton program ass1-skel.c and sample data file data1.txt from the LMS Assignment 1 page, and check that you can compile the program via either grok or gcc. Note that if you plan to use grok, you will need to learn how to execute programs in grok via the “terminal” interface that it provides. There is a handout linked from the LMS that provides guidance.
The skeleton file provides an empty main program that includes a very important authorship dec- laration. Substantial mark penalties apply if you do not include it in your submission, or do not sign it. The skeleton program also includes two very useful pre-filled “constant” matrices. Make sure that you understand their roles, described below (and in more detail in the Assignment 1 video). Those global matrices are intended to be constant, and you should not change their values in any way.

![page1image14459216](https://github.com/clarissaso/Sudoku-Algorithm/assets/80309625/8b4de7c9-ca68-4278-b96b-0939c4f5612e)
Figure 1: An "Easy" sudoku.
