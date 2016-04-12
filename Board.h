/* 
=============================================================================
 * File         :  Board.h
 * Author       :  Christopher MacDonald
 * 
 * FILENAME:  
 *      Board.h -- Board header file for Sudoku Lab
 * FUNCTIONAL DESCRIPTION:
 *      This program in C++ fulfills the requirements of the Sudoku Lab in 
 *      CSCI2101 Fall 2014.
 * 
 *      This header file defines the Board class.  The specific components of 
 *      the class defined in this file are the constructor, six function 
 *      prototypes, and three private members of the class.  The private members
 *      are ints keeping track of the number or rows and columns, and an array
 *      of ints that is the game board.  The function prototypes are getValue,
 *      setValue, nextMove, legalMove, success, and printPuzzle.
 * 
 * NOTICE:
 *      Copyright (C) 2014 Christopher MacDonald    All rights reserved.
 * 
 *===========================================================================
 */

#ifndef BOARD_H
#define	BOARD_H

#include <string>
#include <fstream>
#include <iostream>
#include "Move.h"

//declaration of named constants
#define MAX_ROWS 9
#define MAX_COLS 9
#define CHAR_CONVERTER 48
#define SUB_SQUARE_SIZE 3
#define NUM_SUB_SQUARES 9

using namespace std;

//Defines a board class.  A board is a 2-D array of ints
class Board {
public:
    //constructor
    Board();
    
    //function prototypes
    int getValue(int row, int col);
    void setValue(int row, int col, int value);
    Move nextMove();
    bool legalMove(Move move);
    bool success();
    void printPuzzle();
    
private:
    //declaration of variables used in board object
    int numRows;
    int numCols;
    int theBoard[MAX_ROWS][MAX_COLS];
};

#endif	/* BOARD_H */

