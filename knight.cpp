/********************************************************************
* knight.cpp
********************************************************************/
#include "piece.h"
#include "knight.h"
#include <iostream>

using namespace std;

void Knight :: setColor(int col)
{
 	if (col == 0)
    	color = 'N';
 	else
    	color = 'n';
}

int Knight :: canMove(int a, int b, int c, int d, Piece board[][8]) 
{
 	// The Knight can move forward two spaces and to the right or the left one space
 	if ((a + 2) == c)
 	{
    	if ((b + 1) == d || (b - 1) == d)
    	{
       		// Check if there are any pieces between the Knight and it's destinatioin
       		/**/
       		return true;
	    }
	 }
	 // The Knight can move backward two spaces and to the right or the left one space
	 else if ((a - 2) == c)
	 {
	    if ((b + 2) == d || (b - 2) == d)
	    {
	       // Check if there are any pieces between the Knight and it's destinatioin
	       /**/
	       return true;      
	    }
	 }
	 // The Knight can move forward or backward one space and to the left or right two spaces
	 else if ((a + 1) == d || (a - 1) == d)
	 {
	    if ((b + 2) == d || (b - 2) == d)
	    {
	       // Check if there are any pieces between the Knight and it's destinatioin
	       /**/
	       return true;
	    }
	 }
	 else 
	    return false;
}