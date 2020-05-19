/*********************************
 * bishop.h
 ********************************/

#ifndef BISHOP_H
#define BISHOP_H
#include <iostream>
#include "piece.h"
using namespace std;

/*************************************************************
 * This child class is specific to a Bishop in a chess game.
 ************************************************************/
class Bishop : public Piece
{
   private:

   public:
      void setColor(int col);
      int canMove(int a, int b, int c, int d, Piece board[][8]); 
};

#endif /* bishop_h */