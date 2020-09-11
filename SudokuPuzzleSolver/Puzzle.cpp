//---------------------------------------------------------------------------
// File: Puzzle.cpp
// Author: Snehal Jogdand
// Date: 11/13/2019
// Program 3: Sudoku - Implementing Backtracking
//
// DESCRIPTION:
// Square: 
//    The class file for Puzzle class
//    The Puzzle class holds the representation of a sudoku puzzle. 
//    It does this by holding an 9 x 9 array of Square objects
//---------------------------------------------------------------------------

#include "Puzzle.h"
#include <ostream>
#include <istream>

using namespace std;

/** Default constructor for Puzzle class. */
Puzzle::Puzzle()
{
   for (int row = 0; row < 9; row++)
      for (int col = 0; col < 9; col++)
         square[row][col].setValue(0);

   variables = 0;
}

/** Gets the value at given row and col position.
     @param row  The row position
     @param col  The col position
     @return The value at given position
 */
int Puzzle::get(const int& row, const int& col)
{
   return square[row][col].getValue();
}

/** Sets the value at given row and col position.
     @param row  The row position
     @param col  The col position
     @param value  The value to be set
     @return false if value cannot be set
 */
bool Puzzle::set(const int& row, const int& col, int value)
{
   // check if the value is already fixed
   if (get(row, col) != -1)
      return false;

   // check row constraint
   for (int col = 0; col < 9; col++)
      if (get(row, col) == value)
         return false;

   // check column constraint
   for (int row = 0; row < 9; row++)
      if (get(row, col) == value)
         return false;

   // check block constraint
   int rowOffset = row - row % 3;
   int colOffset = col - col % 3;
   for (int i = 0; i < 3; i++)
      for (int j = 0; j < 3; j++)
         if (get(i + rowOffset, j + colOffset) == value)
            return false;

   // all constraints passed - set the value
   square[row][col].setValue(value);
   return true;
}

/** Returns The number of variable entries in the puzzle
    @return the number of variable entries in the puzzle
*/
int Puzzle::size()
{
   return variables;
}

/** Returns the current number of empty squares (those without any value)
    @return the current number of empty squares
*/
int Puzzle::numEmpty()
{
   int count = 0;
   for (int row = 0; row < 9; row++)
      for (int col = 0; col < 9; col++)
         if (get(row, col) == -1)
            count++;

   return count;
}

/** The sudoku puzzle solver method.
    @return True if the sudoku puzzle is solved, false elsewise
*/
bool Puzzle::solve()
{
   return solve(0, 0);
}

/** The backtracking method to solve the sudoku puzzle.
    @param row  The row position
    @param col  The col position
    @return True if the sudoku puzzle is solved, false elsewise
*/
bool Puzzle::solve(int row, int col)
{
   // if column past end of puzzle, reset column and try next row
   if (col == 9)
   {
      row++;
      col = 0;
   }

   // if (row, column) past end of puzzle, return success
   if (row == 9) return true;

   // move to next square without a value
   if (get(row, col) != -1) return solve(row, col + 1);

   for (int value = 1; value <= 9; value++)
   {
      // if value is legal, set square to it
      if (set(row, col, value))
      {
         if (solve(row, col + 1)) return true;
         else
         {
            // erase square value
            square[row][col].setValue(0);
         }
      }
   }

   // return failure
   return false;
}

/** Default constructor for Square class. */
Puzzle::Square::Square() : value(0), isFixed(false)
{
}

/** Gets the current value of the square object.
    @return The value
 */
int Puzzle::Square::getValue() const
{
   if (isFixed) return value;
   else return -1;
}

/** Sets the current value of the square object.
     @param value  The value to be set
 */
void Puzzle::Square::setValue(const int& value)
{
   if (value == 0)
   {
      isFixed = false;
      this->value = -1;
   }
   else
   {
      isFixed = true;
      this->value = value;
   }
}

/** destructor */
Puzzle::~Puzzle()
{
}