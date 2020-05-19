/********************************************************************
* king.cpp
********************************************************************/
#include "piece.h"
#include "king.h"
#include <iostream>

using namespace std;

/************************************************************
 * This child class is specific to a King in a chess game.
 ***********************************************************/
void King :: setColor(int col)
{
	if (col == 0)
	   color = 'K';
	else
	   color = 'k';
}

/************************************************************
 * This child class is specific to a King in a chess game.
 ***********************************************************/
int King :: canMove(int a, int b, int c, int d, Piece board[][8]) 
{
	// The King can move forward or backward one square in any direction
	if ((a + 1) == c || (a - 1) == c || a == c)
	{
	   if ((b + 1) == d || (b - 1) == d)
	   {
	     return true;
	   }
	}
	// The King can move one square to the right or left
	 else if (b == d)
	{
	   if ((a + 1) == c || (a - 1) == c)
	   {
	      return true;
	   }
	}
	else
	   return false;
}