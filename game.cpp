/*************************************************************
 * This is the full chess program in C++
 ************************************************************/

#include <iomanip>
#include <iostream>
using namespace std;

bool options(char board[][8]);
char initialBoard(char board[][8]);
char move(char board[][8]);
char display(char board[][8]);
char convertLetter(char let);
int convertNumber(char num);
int convertNumberInverse(char num);


int main()
{
	// Create and display board with starting peace positions
    char board[8][8];
    initialBoard(board);
    display(board);

    // Display main menu and start game
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

bool options(char board[][8])
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

char initialBoard(char board[][8])
{
	char p  = 'p';  // Pawn
	char r  = 'r';  // Rook
	char k  = 'n';  // Knight
	char b  = 'b';  // Bishop
	char q  = 'q';  // Queen
	char kk = 'k';  // King
	char e  = ' ';  // Empty

	char P  = 'P';  // Pawn
	char R  = 'R';  // Rook
	char K  = 'N';  // Knight
	char B  = 'B';  // Bishop
	char Q  = 'Q';  // Queen
	char KK = 'K';  // King

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
	board[0][0] = r;
	board[0][1] = k;
	board[0][2] = b;
	board[0][3] = q;
	board[0][4] = kk;
	board[0][5] = b;
	board[0][6] = k;
	board[0][7] = r;

	// Collumn 7

	for (int i = 0; i < 8; ++i)
	{
		board[1][i] = p;
	}

	// Bottom rows of board

	// Collumn 2
	for (int i = 0; i < 8; ++i)
	{
		board[6][i] = P;
	}

	// Collumn 1
	board[7][0] = R;
	board[7][1] = K;
	board[7][2] = B;
	board[7][3] = Q;
	board[7][4] = KK;
	board[7][5] = B;
	board[7][6] = K;
	board[7][7] = R;

	for (int i = 2; i < 6; ++i)
	{
		for (int j = 0; j < 8; ++j)
		{
			board[i][j] = e;
		}
	}
}

char move(char board[][8])
{
	char fLet,fNum,tLet,tNum;
	int fl,fn,tl,tn;

	cout << "\nWhat are the coordinates you are moving from? ";
	cin  >> fLet >> fNum;
	cout << "\nWhat are the coordinates you are moving to? ";
	cin  >> tLet >> tNum;

	//cout << fLet << fNum << " " << tLet << tNum << endl;

	fLet = convertLetter(fLet);
	tLet = convertLetter(tLet);
	
	fl = convertNumber(fLet);
	fn = convertNumberInverse(fNum);
	tl = convertNumber(tLet);
	tn = convertNumberInverse(tNum);

	/*cout << "\n\nfl = " << fl << " " << "fn = " << fn 
		 << " " << "tl = " << tl << " " << "tn = " << tn << endl << endl;

	cout << "from = " << tl << tn << " = " << board[tn][tl] << " to = " << fl << fn << " = " << board[fn][fl] << endl;*/

	board[tn][tl] = board[fn][fl];
	board[fn][fl] = ' ';

	//cout << "from = " << tl << tn << " = " << board[tn][tl] << " to = " << fl<< fn << " = " << board[fn][fl] << endl;

	display(board);
}

char display(char board[][8])
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
			cout << " " << board[i][j] << " |";
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
