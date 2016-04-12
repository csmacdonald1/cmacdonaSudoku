/* 
 *=============================================================================
 * File         :  Move.cpp
 * Author       :  Christopher MacDonald
 * 
 * FILENAME:  
 *      Move.cpp -- move class file for Sudoku Lab
 * FUNCTIONAL DESCRIPTION:
 *      This program in C++ fulfills the requirements of the Sudoku Lab in 
 *      CSCI2101 Fall 2014.
 * 
 *      This source file contains the code to create a Move object.  A move 
 *      object stores three integer components which are a row index, a column
 *      index, and a value.  The Move class has three functions: getColumn, 
 *      getDigit, and getRow, which return the row, column, and digit/value of 
 *      the move object respectively.   These three functions are defined in the
 *      Move header file (Move.h).
 *     
 * NOTICE:
 *      Copyright (C) 2014 Christopher MacDonald    All rights reserved.
 * 
 *=============================================================================
 */

#include "Move.h"

/*
 * FUNCTION NAME: 
 *      Move (Constructor) -- initializes the Move object
 * FUNCTIONAL DESCRIPTION:
 *      The constructor initializes or creates a Move object.  A move object
 *      is a simple object used to keep track of three important values: the
 *      row index, column index, and the number at that index.  By storing this
 *      information in a Move objects, the program has a way to refer to each 
 *      move it has made in the game of Sudoku.
 * ENTRY PARAMETERS:
 *      int row -- a row index value
 *      int col -- a column index value
 *      int entry -- a number at that row and column index
 * RETURN VALUES:
 *      None.
 */

Move::Move(int row, int col, int entry) {
    //sets the private variables in the Move object equal to the inputted 
    //values
    this->row=row;
    this->col=col;
    this->digitEntry=entry;
}



