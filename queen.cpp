/********************************************************************
* queen.cpp
********************************************************************/
#include "piece.h"
#include "queen.h"
#include <iostream>

using namespace std;

void Queen :: setColor(int col)
{
	if (col == 0)
	   color = 'Q';
	else
	   color = 'q';
}

// This function establishes where a Queen can move in any situation
int Queen :: canMove(int a, int b, int c, int d, Piece board[][8]) 
{
	// The Queen can move disgonally left in either direction
	if ((c - a) == (d - b))
	{
	   // Check if there are any pieces between the Queen and it's destinatioin
	   /**/
	   return true;
	}
	// The Queen can move disgonally right in either direction
	else if ((c + a) == (d + b))
	 {
	   // Check if there are any pieces between the Queen and it's destinatioin
	   /**/
	   return true;
	}
	// The Queen can move vertically in either direction
	 else if (a == c && b != d)
	{
	   // Check if there are any pieces between the Queen and it's destinatioin
	   /**/
	   return true;
	}
	 // The Queen can move horizontally in either direction
	else if (a != c && b == d)
	{
	   // Check if there are any pieces between the Queen and it's destinatioin
	   /**/
	    return true;
	}
	else
	   return false;
}