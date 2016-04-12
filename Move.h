/* 
 *=============================================================================
 * File         :  Move.h
 * Author       :  Christopher MacDonald
 * 
 * FILENAME:  
 *      Move.h -- move header file for Sudoku Lab
 * FUNCTIONAL DESCRIPTION:
 *      This program in C++ fulfills the requirements of the Sudoku Lab in 
 *      CSCI2101 Fall 2014.
 * 
 *      This header file defines the Move class.  The specific components of the 
 *      Move class defined in this file are the public members of the class, 
 *      which are a constructor and three functions, as well as the private 
 *      members of the class.  The private members of a Move object are three 
 *      ints: row, col, and digitEntry.  The three public member functions 
 *      getRow, getColumn, and getDigit, return the values of the three private
 *      members respectively.  
 * 
 * NOTICE:
 *      Copyright (C) 2014 Christopher MacDonald    All rights reserved.
 * 
 *===========================================================================
 */

#ifndef MOVE_H
#define	MOVE_H

//Defines the Move class.  A move object holds row and column indices along 
//with a value
class Move {
public:
    //constructor
    Move(int row, int col, int entry);
    
    //functions
    int getRow(){return row;};
    int getColumn(){return col;};
    int getDigit(){return digitEntry;};
private:
    //declaration of variables used in Move object
    int row;
    int col;
    int digitEntry;
};

#endif	/* MOVE_H */

