/*************************************************************
 * This is the full chess program in C++
 ************************************************************/

#include <iomanip>
#include <iostream>
#include "piece.h"
using namespace std;

bool options(Piece board[][8]);
void initialBoard(Piece board[][8]);
void move(Piece board[][8]);
char display(Piece board[][8]);
char convertLetter(char let);
int convertNumber(char num);
int convertNumberInverse(char num);


int main()
{
	// Create and display board with starting peace positions
    Piece board[8][8];
    initialBoard(board);
    display(board);

    //Display main menu and start game
    cout << "Options:\n"
	   	 << "   ? Show options\n"
	   	 << "   D Display the board\n"
	   	 << "   M Make a move\n"
	   	 << "   E End game\n"
	   	 << endl;

	cout << "Please enter a command: ";

    options(board);

    return 0;
}

bool options(Piece board[][8])
{
	char ans;

	// Display main menu and start game
	while (1)
	{
		cin >> ans;

		if (ans == '?')
		{
			cout << "\nOptions:\n"
	    	 << "   ? Show options\n"
	    	 << "   D Display the board\n"
	    	 << "   M Make a move\n"
	    	 << "   E End game\n"
	    	 << endl
	    	 << "Please enter a command: ";
		}
		else if (ans == 'D' || ans == 'd')
		{
			display(board);
			cout << "Please enter a command: ";
		}
		else if (ans == 'M' || ans == 'm')
		{
			move(board);
			cout << "Please enter a command: ";
		}
		else if (ans == 'E' || ans == 'e')
		{
			char temp;
			cout << "\nIf you end the game, all data will be erased,\nare you sure you want to continue?"
				 << "\n\nY or N: ";
			cin  >> temp;

			if (temp == 'y' || temp == 'Y')
			{
				cout << "\nThank you for playing!\n\n";
				return 0;
			}
			else
			{
				cout << "\nYou have chosen to continue playing.\n\n"
					 << "Please enter a command: ";
			}	
		}
		else 
		{
			cout << "\nSorry, your command was not recognized.\n\n"
				 << "Please enter a command: ";
		}
	}
}

void initialBoard(Piece board[][8])
{

	Space e;  // Empty square

	Pawn p00; p00.setColor(0);
    Pawn p01; p01.setColor(0);
    Pawn p02; p02.setColor(0);
    Pawn p03; p03.setColor(0);
    Pawn p04; p04.setColor(0);
    Pawn p05; p05.setColor(0);
    Pawn p06; p06.setColor(0);
    Pawn p07; p07.setColor(0);

    Rook r00; r00.setColor(0);
    Rook r01; r01.setColor(0);

    Bishop b00; b00.setColor(0);
    Bishop b01; b01.setColor(0);

    Knight n00; n00.setColor(0);
    Knight n01; n01.setColor(0);

    Queen q00; q00.setColor(0);
    King k00; k00.setColor(0);

    //////////////////////////

    Pawn p10; p10.setColor(1);
    Pawn p11; p11.setColor(1);
    Pawn p12; p12.setColor(1);
    Pawn p13; p13.setColor(1);
    Pawn p14; p14.setColor(1);
    Pawn p15; p15.setColor(1);
    Pawn p16; p16.setColor(1);
    Pawn p17; p17.setColor(1);
    
    Rook r10; r10.setColor(1);
    Rook r11; r11.setColor(1);

    Bishop b10; b10.setColor(1);
    Bishop b11; b11.setColor(1);

    Knight n10; n10.setColor(1);
    Knight n11; n11.setColor(1);
    
    Queen q10; q10.setColor(1);
    King k10; k10.setColor(1);

	/*HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
 	// you can loop k higher to see more color choices
  	for(int k = 1; k < 255; k++)
  	{
    	// pick the colorattribute k you want
    	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), k);
    	cout << k << " I want to be nice today!" << endl;
  	}*/

	// Top rows of board

	// Collumn 8
	board[0][0] = r10;
	board[0][1] = n10;
	board[0][2] = b10;
	board[0][3] = q10;
	board[0][4] = k10;
	board[0][5] = b11;
	board[0][6] = n11;
	board[0][7] = r11;

	// Collumn 7
	board[1][0] = p10;
	board[1][1] = p11;
	board[1][2] = p12;
	board[1][3] = p13;
	board[1][4] = p14;
	board[1][5] = p15;
	board[1][6] = p16;
	board[1][7] = p17;

	// Bottom rows of board

	// Collumn 2
	board[6][0] = p00;
	board[6][1] = p01;
	board[6][2] = p02;
	board[6][3] = p03;
	board[6][4] = p04;
	board[6][5] = p05;
	board[6][6] = p06;
	board[6][7] = p07;

	// Collumn 1
	board[7][0] = r00;
	board[7][1] = n00;
	board[7][2] = b00;
	board[7][3] = q00;
	board[7][4] = k00;
	board[7][5] = b01;
	board[7][6] = n01;
	board[7][7] = r01;

	for (int i = 2; i < 6; ++i)
	{
		for (int j = 0; j < 8; ++j)
		{
			board[i][j] = e;
		}
	}
}

void move(Piece board[][8])
{
	char fLet,fNum,tLet,tNum,ph; // from letter, from number, placeholder, to letter, to number
	int fl,fn,tl,tn;             // abbreviated variables translated to intigers
	bool check = false;
	Space e;

	while (check != true)
	{
		cout << "\nEnter your move (b2:b4): ";
		cin  >> fLet >> fNum >> ph >> tLet >> tNum;

		fLet = convertLetter(fLet);
		tLet = convertLetter(tLet);
		
		fl = convertNumber(fLet);
		fn = convertNumberInverse(fNum);
		tl = convertNumber(tLet);
		tn = convertNumberInverse(tNum);

		// cout << fl << " " << fn << " " << tl << " " << tn << endl;board[fn][fl].canMove(fn, fl, tn, tl)
		// cout << board[fn][fl].color << endl;
		// if (board[fn][fl].canMove(fn, fl, tn, tl))
		// 	check = true;
		// else
		// 	cout << "\nError: Illegal move.";
		cout << board[1][7].canMove(1, 2, 1, 4) << endl;
		//board[1][7].setColor(1);
	}

	board[tn][tl] = board[fn][fl];
	board[fn][fl] = e;

	display(board);
}

char display(Piece board[][8])
{
	// Board compenents
	string bs = "-";     // Boarder Start
	string bb = "----";  // Boarder
	string ss = "|";     // Square Start

	string boarder = "   " + bs + bb + bb + bb + bb + bb + bb + bb + bb + "\n";

	// Board and pieces
	for (int i = 0; i < 8; ++i)
	{
		cout << endl << boarder << " " << 8 - i << " " << ss;
		for (int j = 0; j < 8; ++j)
		{
			cout << " ";
			cout << board[i][j].color;
			cout << " |";
		}
	}

	cout << endl << boarder;
	cout << "     A   B   C   D   E   F   G   H\n\n";
}

/*********************************************************************
 * This function converts char letters into char numbers for display.
 ********************************************************************/
char convertLetter(char let)
{
   // Declare letter variable for return
   char letter;

   // Translate char letter to char number
   if (let == 'A' || let == 'a')
      letter = '1';
   if (let == 'B' || let == 'b')
      letter = '2';
   if (let == 'C' || let == 'c')
      letter = '3';
   if (let == 'D' || let == 'd')
      letter = '4';
   if (let == 'E' || let == 'e')
      letter = '5';
   if (let == 'F' || let == 'f')
      letter = '6';
   if (let == 'G' || let == 'g')
      letter = '7';
   if (let == 'H' || let == 'h')
      letter = '8';
      
   return letter;  
}

/**********************************************************************
 * This function converts char numbers into int numbers for display.
 *********************************************************************/
int convertNumberInverse(char num)
{
   // Declare number variable for return
   int number;

   // Translate char number to int number
   if (num == '1')
      number = 7;
   if (num == '2')
      number = 6;
   if (num == '3')
      number = 5;
   if (num == '4')
      number = 4;
   if (num == '5')
      number = 3;
   if (num == '6')
      number = 2;
   if (num == '7')
      number = 1;
   if (num == '8')
      number = 0;

   return number;
}

/**********************************************************************
 * This function converts char numbers into int numbers for display.
 *********************************************************************/
int convertNumber(char num)
{
   // Declare number variable for return
   int number;

   // Translate char number to int number
   if (num == '1')
      number = 0;
   if (num == '2')
      number = 1;
   if (num == '3')
      number = 2;
   if (num == '4')
      number = 3;
   if (num == '5')
      number = 4;
   if (num == '6')
      number = 5;
   if (num == '7')
      number = 6;
   if (num == '8')
      number = 7;

   return number;
}