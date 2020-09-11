//---------------------------------------------------------------------------
// File: Puzzle.h
// Author: Snehal Jogdand
// Date: 11/13/2019
// Program 3: Sudoku - Implementing Backtracking
//
// DESCRIPTION:
// Square: 
//    The header file for Puzzle class
//    The Puzzle class holds the representation of a sudoku puzzle. 
//    It does this by holding an 9 x 9 array of Square objects
//---------------------------------------------------------------------------

#ifndef PUZZLE_
#define PUZZLE_

#include <iostream>
#include <istream>

using namespace std;

// The Puzzle class holds the representation of a sudoku puzzle. 
// It does this by holding an 9 x 9 array of Square objects
class Puzzle
{
private:
   // The Square class holds all of the information associated with a square 
   // location in the puzzle. This includes the square's numerical value and 
   // a flag indicating if the value is fixed (one of the values given at the 
   // start of the puzzle) or variable (the values written in as parts of a 
   // possible solution)
   class Square
   {
   private:
      int value;     // The value of the square
      bool isFixed;  // Flag indicating if the value is fixed

   public:
      /** constructor */
      Square();

      /** gets the current value of the square object */
      int getValue() const;

      /** sets the current value of the square object */
      void setValue(const int& value);
   };

   Square square[9][9]; // the square object matrix
   int variables;       // count of variables in the matrix which are not fixed

   /** the backtracking method to solve the sudoku puzzle */
   bool solve(int row, int col);

public:
   /** constructor */
   Puzzle();

   /** gets the value at given row and col position */
   int get(const int& row, const int& col);

   /** 
      sets the value at given row and col position 
      returns false if value cannot be set
   */
   bool set(const int& row, const int& col, int value);

   /** the sudoku puzzle solver method */
   bool solve();

   /** returns the number of variable entries in the puzzle */
   int size();

   /** returns the current number of empty squares (those without any value) */
   int numEmpty();

   /** overload the stream input operator to write sudoku puzzle result */
   friend ostream& operator<<(ostream& output, Puzzle& puzzle);

   /** overload the stream input operator to read sudoku puzzle */
   friend istream& operator>>(istream& input, Puzzle& puzzle);

   /** destructor */
   virtual ~Puzzle();
};

#endif