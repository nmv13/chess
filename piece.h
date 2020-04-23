/*********************************
 * piece.h
 ********************************/

#ifndef PIECE_H
#define PIECE_H
#include <iostream>
using namespace std;

class Piece
{
   protected:
      bool alive;
      bool first;

   public:
      Piece()
      {
         alive = true;
         first = true;
      }
      char color;                                // Holds display piece
      void setColor(int col);                    // Set piece color
      bool isAlive() { return alive; }           // Check to see if piece is alive
      int canMove(int a, int b, int c, int d);   // Check if piece can be moved
};

class Pawn : public Piece
{
   private:

   public:
      void setColor(int col)
      {
         if (col == 0)
            color = 'P';
         else
            color = 'p';
      }

      int canMove(int a, int b, int c, int d) 
      {  
         if (a == c && (b + 2) == d)
            if (first)
            {
               first = false;
               return true;
            }
         else if (a == c && (b + 1) == d)
         {
            first = false;
            return true;
         }
         else if ((a + 1) == c && (b + 1) == d)
         {
            first = false;
            return true;
         }
         else if ((a - 1) == c && (b - 1) == d)
         {
            first = false;
            return true;
         }
         else
            return false;
      }
};

class Rook : public Piece
{
   private:

   public:
      void setColor(int col)
      {
         if (col == 0)
            color = 'R';
         else
            color = 'r';
      }

      int canMove(int a, int b, int c, int d) 
      {
         if (a == c && b != d)
            return true;
         else if (a != c && b == d)
            return true;
         else
            return false;         
      }
};

class Knight : public Piece
{
   private:

   public:
      void setColor(int col)
      {
         if (col == 0)
            color = 'N';
         else
            color = 'n';
      }

      int canMove(int a, int b, int c, int d) 
      {
         if ((a + 2) == c)
         {
            if ((b + 1) == d || (b - 1) == d)
               return true;
         }
         else if ((a - 2) == c)
         {
            if ((b + 2) == d || (b - 2) == d)
               return true;      
         }
         else if ((a + 1) == d || (a - 1) == d)
         {
            if ((b + 2) == d || (b - 2) == d)
               return true;
         }
         else 
            return false;
      }
};

class Bishop : public Piece
{
   private:

   public:
      void setColor(int col)
      {
         if (col == 0)
            color = 'B';
         else
            color = 'b';
      }

      int canMove(int a, int b, int c, int d) 
      {
         if ((c - a) == (d - b))
            return true;
         else if ((c + a) == (d + b))
            return true;
         else
            return false;
      }
};

class Queen : public Piece
{
   private:

   public:
      void setColor(int col)
      {
         if (col == 0)
            color = 'Q';
         else
            color = 'q';
      }

      int canMove(int a, int b, int c, int d) 
      {
         if ((c - a) == (d - b))
            return true;
         else if ((c + a) == (d + b))
            return true;
         else if (a == c && b != d)
            return true;
         else if (a != c && b == d)
            return true;
         else
            return false;
      }
};

class King : public Piece
{
   private:

   public:
      void setColor(int col)
      {
         if (col == 0)
            color = 'K';
         else
            color = 'k';
      }

      int canMove(int a, int b, int c, int d) 
      {
         if ((a + 1) == c || (a - 1) == c || a == c)
         {
            if ((b + 1) == d || (b - 1) == d)
               return true;
         }
         else if (b == d)
         {
            if ((a + 1) == c || (a - 1) == c)
               return true;
         }
         else
            return false;
      }
};

class Space : public Piece
{
   public:
      Space()
      {
         color = ' ';
      }

      int canMove(int a, int b, int c, int d)
      {
         return false;
      }
};

#endif /* piece_h */