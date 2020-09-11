//---------------------------------------------------------------------------
// File: SortedListDriver.cpp
// Author: Snehal Jogdand
// Date: 11/13/2019
// Program 3: Sudoku - Implementing Backtracking
//
//---------------------------------------------------------------------------
// DESCRIPTION:
// The program solves a 9-by-9 sudoku problem
//---------------------------------------------------------------------------
// IMPLEMENTATION:
//  The algorithm for sudoku backtracking
//    Solve(row, column)
//       Move to next square without a value
//       if (row, column) past end of puzzle, return success
//       foreach value from 1 through 9
//          if value is legal, set square to it
//             if Solve(next row and column) succeeds
//          return success
//          endif
//          erase square value
//       endif
//       endfor
//       return failure
//    end Solve

//---------------------------------------------------------------------------
// ASSUMPTIONS:
//    Input:
//       The input format consists of a sequence of 81 numerical digits, as ASCII text, 
//       each corresponding to the contents of one square in the puzzle grid, in row-major
//       order (i.e., starting at the upper left corner, reading across each row and 
//       then continuing with the next row, ending at the bottom right corner). 
//       Blank squares are represented with zeros. Any non-digit characters would be ignored
//       Example input 1: valid 81 numerical digits without any ascii text.
//          423751968759683124168249357945362871872915436316478295537194682691827543284536019
//       Example input 2 : valid 81 numerical digits with few ascii text which are ignored.
//          42375196875968312416824-this-is-sample-text-which-is-ignored-
//          9357945362871872915436316478295537194682691827543284536019
//
//    Exiting Program:
//       Program will exit after printing the sudoku output.
//    Output:
//      The output of the program would be a formatted text - 11 lines of text, with 
//       each line containing the numbers in a row of the puzzle separated by single 
//       spaces. The '|', '+', and '-' characters are used to separate 3-by-3 blocks
//       (each line of output should be 19 printing characters long: 9 digits, 8 spaces,
//       and 2 '|' for "non-divider" lines and 17 '-' and 2 '+' for "divider" lines).
//       Example output:
//
//          4 2 3 | 7 5 1 | 9 6 8
//          7 5 9 | 6 8 3 | 1 2 4
//          1 6 8 | 2 4 9 | 3 5 7
//          ------+-------+------
//          9 4 5 | 3 6 2 | 8 7 1
//          8 7 2 | 9 1 5 | 4 3 6
//          3 1 6 | 4 7 8 | 2 9 5
//          ------+-------+------
//          5 3 7 | 1 9 4 | 6 8 2
//          6 9 1 | 8 2 7 | 5 4 3
//          2 8 4 | 5 3 6 | 7 1 9
//---------------------------------------------------------------------------

#include <iostream>
#include <string>
#include <sstream>
#include "Puzzle.h"

using namespace std;

int main()
{
   Puzzle puzzle;
   cin >> puzzle;

   if (!puzzle.solve())
   {
      cout << "Could not solve the Sudoku puzzle.";
   }
   else
   {
      cout << puzzle;
   }
}