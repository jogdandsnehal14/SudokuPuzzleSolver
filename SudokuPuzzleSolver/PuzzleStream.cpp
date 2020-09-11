//---------------------------------------------------------------------------
// File: PuzzleStream.cpp
// Author: Snehal Jogdand
// Date: 11/13/2019
// Program 3: Sudoku - Implementing Backtracking
//
// DESCRIPTION:
// PuzzleStream: 
//    The puzzle stream file holds the methods to overload the stream input
//    and output operator. The input stream operator would enable Puzzle class
//    to read the puzzle in compact format. The output stream operator would 
//    print the sudoku result.
//---------------------------------------------------------------------------

#include <iostream>
#include <istream>
#include "Puzzle.h"

using namespace std;

ostream& operator<<(ostream& output, Puzzle& puzzle)
{
   for (int row = 0; row < 9; row++)
   {
      cout << " ";
      for (int col = 0; col < 9; col++)
      {
         cout << puzzle.get(row, col);
         if (col == 2 || col == 5)
            cout << "|";
         else
            cout << " ";
      }

      if (row == 2 || row == 5)
         cout << endl << "------+-----+------";

      cout << endl;
   }

   return output;
}

istream& operator>>(istream& input, Puzzle& puzzle)
{
   char c;
   int count = 0, row = 0, col = 0;
   while (count < 81) {
      input >> c;
      if (c >= '0' && c <= '9')
      {
         int val = c - '0';

         if (val != 0 && !puzzle.set(row, col, val))
         {
            cout << "Invalid input" << endl;
            break;
         }
         else
            puzzle.square[row][col].setValue(val);

         if (puzzle.get(row, col) == -1) puzzle.variables++;

         col++;
         if (col >= 9)
         {
            col = 0;
            row++;
         }

         count++;
      }
   }

   return input;
}