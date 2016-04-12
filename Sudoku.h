/* 
=============================================================================
 * File         :  Sudoku.h
 * Author       :  Christopher MacDonald
 * 
 * FILENAME:  
 *      Sudoku.h -- Sudoku header file for Sudoku Lab
 * FUNCTIONAL DESCRIPTION:
 *      This program in C++ fulfills the requirements of the Sudoku Lab in 
 *      CSCI2101 Fall 2014.
 * 
 *      This header file defines the Sudoku class.  The specific components
 *      of the Sudoku class defined in this file are the constructor and one 
 *      function prototype, as well as two private members.  The constructor 
 *      creates or initializes a Sudoku object.  The function "solve" solves a
 *      Sudoku puzzle.  The private members of a Sudoku object are a stack of 
 *      moves and a board object.  
 * NOTICE:
 *      Copyright (C) 2014 Christopher MacDonald    All rights reserved.
 * 
 *===========================================================================
 */

#ifndef SUDOKU_H
#define	SUDOKU_H

#include "Board.h"
#include "Move.h"
#include <stack>

//declaration of named constant
#define MAX_DIGITS 9

using namespace std;

//Defines the Sudoku class.  A Sudoku object is a 2-D array of digits and a 
//series of moves
class Sudoku {
public:
    //constructor
    Sudoku();
    
    //function prototype
    void solve();
   
private:
    //declaration of variables contained in a Sudoku object
    stack<Move> theStack;
    Board theBoard;

};

#endif	/* SUDOKU_H */

