/* 
 *=============================================================================
 * File         :  Main.cpp
 * Author       :  Christopher MacDonald
 * 
 * FILENAME:  
 *      Main.cpp -- main file for Sudoku Lab
 * FUNCTIONAL DESCRIPTION:
 *      This program in C++ fulfills the requirements of Sudoku Lab in 
 *      CSCI2101 Fall 2014.
 * 
 *      This source file contains the code to create and solve a Sudoku 
 *      puzzle. Upon its start, the file welcomes the user to Sudoku and 
 *      asks the user to input a puzzle file.  The program then prints out the 
 *      puzzle (as long as it is rectangular!) and displays its dimensions. The 
 *      program then solves the Sudoku puzzle and prints out the filled in 
 *      board along with a message congratulating the user.  
 *     
 * NOTICE:
 *      Copyright (C) 2014 Christopher MacDonald    All rights reserved.
 * 
 *===========================================================================
 */

#include <cstdlib>
#include "Board.h"
#include "Sudoku.h"
#include "Move.h"
using namespace std;

int main(int argc, char** argv) {
    
    //welcome message
    cout<<"Welcome to Sudoku!\n\n";
    
    //creates and solves sudoku puzzle
    Sudoku mySudoku;
    mySudoku.solve();   
    return 0;
}

