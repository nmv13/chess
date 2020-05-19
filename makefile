###############################################################
# Program:
#     Chess
# Author:
#     Nakai Velasquez
# Summary:
#     This program allows the game of chess to be played, with 
#     standard rules and regulations.
###############################################################


a.out : main.o piece.o pawn.o bishop.o knight.o rook.o queen.o king.o
	g++ main.o piece.o pawn.o bishop.o knight.o rook.o queen.o king.o

main.o : main.cpp piece.h
	g++ -c main.cpp

piece.o : piece.h piece.cpp
	g++ -c piece.cpp

pawn.o : piece.h pawn.h pawn.cpp
	g++ -c pawn.cpp

bishop.o : piece.h bishop.h bishop.cpp
	g++ -c bishop.cpp

knight.o : piece.h knight.h knight.cpp
	g++ -c knight.cpp

rook.o : piece.h rook.h rook.cpp
	g++ -c rook.cpp

queen.o : piece.h queen.h queen.cpp
	g++ -c queen.cpp

king.o : piece.h king.h king.cpp
	g++ -c king.cpp

clean :
	rm *.o a.out