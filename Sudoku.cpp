/* 
 *=============================================================================
 * File         :  Sudoku.cpp
 * Author       :  Christopher MacDonald
 * 
 * FILENAME:  
 *      Sudoku.cpp -- Sudoku class file for Sudoku Lab
 * FUNCTIONAL DESCRIPTION:
 *      This program in C++ fulfills the requirements of the Sudoku Lab in 
 *      CSCI2101 Fall 2014.
 * 
 *      This source file contains the constructor and functions for the Sudoku
 *      class.  The constructor creates and initializes a Sudoku object.  
 *      The solve function methodically goes through an incomplete Sudoku puzzle
 *      and correctly fills in the empty spaces until the puzzle is complete.
 *      
 * NOTICE:
 *      Copyright (C) 2014 Christopher MacDonald    All rights reserved.
 * 
 *===========================================================================
 */

#include "Sudoku.h"
/*
 * FUNCTION NAME: 
 *      Sudoku (Constructor) -- initializes the Sudoku object
 * FUNCTIONAL DESCRIPTION:
 *      The constructor initializes or creates the Sudoku object.  A Sudoku 
 *      object contains a board, or an array of ints.  It also contains a stack
 *      on which new moves can be placed or from which they can be removed.   
 * ENTRY PARAMETERS:
 *      None.
 * RETURN VALUES: 
 *      None.
 */
Sudoku::Sudoku() {
    
    //prints the board, puts the first move on the stack, and updates the board
    theBoard.printPuzzle();    
    Move first=theBoard.nextMove();
    theStack.push(first);
    theBoard.setValue(first.getRow(),first.getColumn(),first.getDigit());
    
}

/*
 * FUNCTION NAME: 
 *      Solve -- solves a Sudoku puzzle
 * FUNCTIONAL DESCRIPTION:
 *      This function solves a sudoku puzzle.  It does this by finding the next
 *      available move for the puzzle, putting it on the stack, and updating the
 *      board.  Every time the function fails to find a new legal move, it 
 *      backtracks and removes the top move from the stack. It then updates the
 *      former top move by incrementing its value if possible.  If this is not
 *      possible, the function keeps popping off the top moves until it finds
 *      one that can be revised.  Once it has revised the top move, it continues 
 *      moving forward to solve the puzzle.  Once the puzzle has been   
 *      successfully completed, the function ends.   
 * ENTRY PARAMETERS:
 *      None.
 * RETURN VALUES: 
 *      None.
 */
void Sudoku::solve(){
    
    //declaration of variables
    bool repeatedMove=0;
    bool goodMove=0;
    int savedValue;
    int value;
    int row;
    int col;
    Move topMove(0,0,0);
    Move newTop(0,0,0);
    
    //function runs as long as the board has not been successfully completed
    while(!theBoard.success()){
    
        //if there is a legal next move, add it to the stack and to the board    
        if(theBoard.nextMove().getDigit()!=0){
            Move next=theBoard.nextMove();
            theStack.push(next);
            theBoard.setValue(next.getRow(),next.getColumn(),next.getDigit());
        }
        //if there is no legal next move, backtrack and revise a previous move
        else {
            do{

                //save all the value and index of the first top move that does 
                //not have a value of 9, then pop it off the stack
                topMove=theStack.top();
                savedValue=topMove.getDigit();
                row=topMove.getRow();
                col=topMove.getColumn();
                value=savedValue+1;
                theBoard.setValue(row,col,0);
                theStack.pop();
                
                //revise the top move by adding 1 to its value until it is legal
                //then start moving forward again by finding the next move 
                goodMove=0;
                for(value;value<=MAX_DIGITS;value++){
                    newTop=Move(row,col,value);
                    //if the move is legal, add it to the stack and update the 
                    //board
                    if(theBoard.legalMove(newTop)){
                        theStack.push(newTop);
                        theBoard.setValue(row,col,value);
                        goodMove=1;
                        break;
                    }
                //if no legal move other than the one that was previously tried 
                //and popped off is possible, then do not add the move back on 
                //the stack            
                }   
                if(!goodMove&&theBoard.nextMove().getDigit()==savedValue){
                    repeatedMove=1;
                }
            //repeat as long as there is no way to revise the top move, or there
            //is no legal next move
            }while(!goodMove && (theBoard.nextMove().getDigit()==0||
                   repeatedMove));
        }     
    }
     
    //prints out the completed puzzle and returns the function
    theBoard.printPuzzle();
    return;
}


                                                                                                                                                                                                             