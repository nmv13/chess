/********************************************************************
* bishop.cpp
********************************************************************/
#include "piece.h"
#include "bishop.h"
#include <iostream>

using namespace std;

/********************************************************************
* Sets the color (case) for the piece on the board
********************************************************************/
void Bishop :: setColor(int col)
{
	if (col == 0)
	   color = 'B';
	else
	   color = 'b';
}

/********************************************************************
* Shows what moves are allowed and what moves are illegal
********************************************************************/
int Bishop :: canMove(int a, int b, int c, int d, Piece board[][8]) 
{
	// The Bishop can move diagonally in any direction
	if ((c - a) == (d - b))
	{
	   // Check if there are any pieces between the Bishop and it's destinatioin
	   /**/
	   return true;
	}
	else if ((c + a) == (d + b))
	{
	   // Check if there are any pieces between the Bishop and it's destinatioin
	   /**/
	   return true;
	}
	else
	   return false;
}