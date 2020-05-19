/*********************************
 * queen.h
 ********************************/

#ifndef QUEEN_H
#define QUEEN_H
#include <iostream>
#include "piece.h"
using namespace std;

/*************************************************************
 * This child class is specific to a Queen in a chess game.
 ************************************************************/
class Queen : public Piece
{
   private:

   public:
      void setColor(int col);
      int canMove(int a, int b, int c, int d, Piece board[][8]); 
};

#endif /* queen_h */