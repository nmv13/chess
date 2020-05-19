/*********************************
 * pawn.h
 ********************************/

#ifndef PAWN_H
#define PAWN_H
#include <iostream>
#include "piece.h"
using namespace std;

/*************************************************************
 * This child class is specific to a Pawn in a chess game.
 ************************************************************/
class Pawn : public Piece
{
   private:

   public:
      void setColor(int col);
      int canMove(int a, int b, int c, int d, Piece board[][8]);
};

#endif /* pawn_h */