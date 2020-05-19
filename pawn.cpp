/********************************************************************
* pawn.cpp
********************************************************************/
#include "piece.h"
#include "pawn.h"
#include <iostream>

using namespace std;

/********************************************************************
* Sets the color (case) for the piece on the board
********************************************************************/
void Pawn :: setColor(int col)
{
 	if (col == 0)
    	color = 'P';
 	else
    	color = 'p';
}

/********************************************************************
* Shows what moves are allowed and what moves are illegal
********************************************************************/
int Pawn :: canMove(int a, int b, int c, int d, Piece board[][8]) 
{  
	// If it is this Pawn's first move of the game, it can move forward 2 squares
	// After first move, first must equal false.
	if (a == c && (b + 2) == d)
	{   
	   if (first)
	   {
	      // Check first move forward to see if a piece is already there
	      if (board[a][b + 1].color != ' ')
	         return false;
	      else
	      {
	         first = false;
	         return true;
	      }
	   }
	}
	// The Pawn can move forward 1 space
	else if (a == c && (b + 1) == d)
	{
	   // Check if another piece is there
	   if (board[a][b + 1].color != ' ')
	      return false;
	   else
	   {
	      first = false;
	      return true;
	   }
	}
	// The Pawn can move one square forward and one square right
	else if ((a + 1) == c && (b + 1) == d)
	{
	   first = false;
	   return true;
	}
	// The Pawn can move one square forward and one square left
	else if ((a - 1) == c && (b - 1) == d)
	{
	   first = false;
	   return true;
	}
	else
	   return false;
}