/*********************************
 * piece.h
 ********************************/

#ifndef PIECE_H
#define PIECE_H
#include <iostream>
using namespace std;

/*************************************************************
 * This class establishes a piece object with all basic 
 * components.
 ************************************************************/
class Piece
{
   protected:
      bool alive;                                // States whether object is alive
      bool first;                                // States whether it is that piece's first move

   public:
      Piece()
      {
         alive = true;
         first = true;
      }
      char color;                                // Holds display piece
      void setColor(int col);                    // Set piece color
      bool isAlive() { return alive; }           // Check to see if piece is alive

      // This function checks where a given piece can move on a chess board in any situation. This 
      // happens by reading in the coordinates of the piece. It does not matter where the piece is 
      // on the board at the time, this function only specifies if the move is allowed or not in general.
      // Other functions will take care of the rest of the work. Essentially, this function reads in 4 numbers 
      // and applies them as if they were on a graph, if the first two (x,y) numbers in relation to the second
      // pair of (x,y) is a valid move from point 1 to point 2 according to the chess piece, then it returns true. 
      int canMove(int a, int b, int c, int d);
};

/*************************************************************
 * This child class is specific to a Pawn in a chess game.
 ************************************************************/
class Pawn : public Piece
{
   private:

   public:
      // Color in this case represents the piece's char case
      void setColor(int col)
      {
         if (col == 0)
            color = 'P';
         else
            color = 'p';
      }

      // This function establishes where a Pawn can move in general situations
      int canMove(int a, int b, int c, int d) 
      {  
         // If it is this Pawn's first move of the game, it can move forward 2 squares
         if (a == c && (b + 2) == d)
            if (first)
            {
               first = false;
               return true;
            }
         // The Pawn can move forward 1 space
         else if (a == c && (b + 1) == d)
         {
            first = false;
            return true;
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
};

/*************************************************************
 * This child class is specific to a Rook in a chess game.
 ************************************************************/
class Rook : public Piece
{
   private:

   public:
      // Color in this case represents the piece's char case
      void setColor(int col)
      {
         if (col == 0)
            color = 'R';
         else
            color = 'r';
      }

      // This function establishes where a Rook can move in general situations
      int canMove(int a, int b, int c, int d) 
      {
         // The Rook can move vertically in either direction
         if (a == c && b != d)
            return true;
         // The ROok can move horizontally in either direction
         else if (a != c && b == d)
            return true;
         else
            return false;         
      }
};

/*************************************************************
 * This child class is specific to a Knight in a chess game.
 ************************************************************/
class Knight : public Piece
{
   private:

   public:
      // Color in this case represents the piece's char case
      void setColor(int col)
      {
         if (col == 0)
            color = 'N';
         else
            color = 'n';
      }

      // This function establishes where a Knight can move in general situations
      int canMove(int a, int b, int c, int d) 
      {
         // The Knight can move forward two spaces and to the right or the left one space
         if ((a + 2) == c)
         {
            if ((b + 1) == d || (b - 1) == d)
               return true;
         }
         // The Knight can move backward two spaces and to the right or the left one space
         else if ((a - 2) == c)
         {
            if ((b + 2) == d || (b - 2) == d)
               return true;      
         }
         // The Knight can move forward or backward one space and to the left or right two spaces
         else if ((a + 1) == d || (a - 1) == d)
         {
            if ((b + 2) == d || (b - 2) == d)
               return true;
         }
         else 
            return false;
      }
};

/*************************************************************
 * This child class is specific to a Bishop in a chess game.
 ************************************************************/
class Bishop : public Piece
{
   private:

   public:
      // Color in this case represents the piece's char case
      void setColor(int col)
      {
         if (col == 0)
            color = 'B';
         else
            color = 'b';
      }

      // This function establishes where a Bishop can move in general situations
      int canMove(int a, int b, int c, int d) 
      {
         // The Bishop can move diagonally in any direction
         if ((c - a) == (d - b))
            return true;
         else if ((c + a) == (d + b))
            return true;
         else
            return false;
      }
};

/*************************************************************
 * This child class is specific to a Queen in a chess game.
 ************************************************************/
class Queen : public Piece
{
   private:

   public:
      // Color in this case represents the piece's char case
      void setColor(int col)
      {
         if (col == 0)
            color = 'Q';
         else
            color = 'q';
      }

      // This function establishes where a Queen can move in any situation
      int canMove(int a, int b, int c, int d) 
      {
         // The Queen can move disgonally left in either direction
         if ((c - a) == (d - b))
            return true;
         // The Queen can move disgonally right in either direction
         else if ((c + a) == (d + b))
            return true;
         // The Queen can move vertically in either direction
         else if (a == c && b != d)
            return true;
         // The Queen can move horizontally in either direction
         else if (a != c && b == d)
            return true;
         else
            return false;
      }
};

/************************************************************
 * This child class is specific to a King in a chess game.
 ***********************************************************/
class King : public Piece
{
   private:

   public:
      // Color in this case represents the piece's char case
      void setColor(int col)
      {
         if (col == 0)
            color = 'K';
         else
            color = 'k';
      }

      // This function establishes where a King can move in any situation
      int canMove(int a, int b, int c, int d) 
      {
         // The King can move forward or backward one square in any direction
         if ((a + 1) == c || (a - 1) == c || a == c)
         {
            if ((b + 1) == d || (b - 1) == d)
               return true;
         }
         // The King can move one square to the right or left
         else if (b == d)
         {
            if ((a + 1) == c || (a - 1) == c)
               return true;
         }
         else
            return false;
      }
};

/*************************************************************
 * This child class takes the place of any square on the 
 * board that is not populated by a chess piece.
 ************************************************************/
class Space : public Piece
{
   public:
      Space()
      {
         color = ' ';    // For this class, the color is a space representing an empty square
      }

      // A space can't move
      int canMove(int a, int b, int c, int d)
      {
         return false;
      }
};

#endif /* piece_h */