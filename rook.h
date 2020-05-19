/*********************************
 * rook.h
 ********************************/

#ifndef ROOK_H
#define ROOK_H
#include <iostream>
#include "piece.h"
using namespace std;

/*************************************************************
 * This child class is specific to a Rook in a chess game.
 ************************************************************/
class Rook : public Piece
{
   private:

   public:
      void setColor(int col);
      int canMove(int a, int b, int c, int d, Piece board[][8]); 
};

#endif /* rook_h */