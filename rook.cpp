/********************************************************************
* rook.cpp
********************************************************************/
#include "piece.h"
#include "rook.h"
#include <iostream>

using namespace std;

void Rook :: setColor(int col)
{
	if (col == 0)
	   color = 'R';
	else
	   color = 'r';
}

int Rook :: canMove(int a, int b, int c, int d, Piece board[][8]) 
{
	// The Rook can move vertically in either direction
	if (a == c && b != d)
	{
	   // Check if there are any pieces between the Rook and it's destinatioin
	   /**/
	   return true;
	}
	// The Rook can move horizontally in either direction
	else if (a != c && b == d)
	{
	   // Check if there are any pieces between the Rook and it's destination
	   /**/
	   return true;
	}
	 else
	   return false;         
}
