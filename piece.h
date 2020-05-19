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
      bool protect;                              // States whether piece is being protected by another piece

   public:
      Piece()
      {
         alive = true;
         first = true;
      }
      char color;                                // Holds display piece
      void setColor(int col);                    // Set piece color
      bool isAlive() { return alive; }           // Check to see if piece is alive

      // This function checks where a given piece can move on a chess board in general situations. This 
      // happens by reading in the coordinates of the piece. It does not matter where the piece is 
      // on the board at the time, this function only specifies if the move is allowed or not in general.
      // Other functions will take care of the rest of the work. Essentially, this function reads in 4 numbers 
      // and applies them as if they were on a graph, if the first two (x,y) numbers in relation to the second
      // pair of (x,y) is a valid move from point 1 to point 2 according to the chess piece, and no additional 
      // pieces are in the way of that path, then it returns true. 
      int canMove(int a, int b, int c, int d, Piece board[][8]);      
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
      int canMove(int a, int b, int c, int d, Piece board[][8])
      {
         return false;
      }
};

#endif /* piece_h */