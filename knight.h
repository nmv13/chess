/*********************************
 * knight.h
 ********************************/

#ifndef KNIGHT_H
#define KNIGHT_H
#include <iostream>
#include "piece.h"
using namespace std;

/*************************************************************
 * This child class is specific to a Knight in a chess game.
 ************************************************************/
class Knight : public Piece
{
   private:

   public:
      void setColor(int col);
      int canMove(int a, int b, int c, int d, Piece board[][8]);
};

#endif /* knight_h */