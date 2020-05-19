/*********************************
 * king.h
 ********************************/

#ifndef KING_H
#define KING_H
#include <iostream>
#include "piece.h"
using namespace std;

/*************************************************************
 * This child class is specific to a king in a chess game.
 ************************************************************/
class King : public Piece
{
   private:

   public:
      void setColor(int col);
      int canMove(int a, int b, int c, int d, Piece board[][8]);
};

#endif /* king_h */