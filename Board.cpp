/* 
=============================================================================
 * File         :  Board.cpp
 * Author       :  Christopher MacDonald
 * 
 * FILENAME:  
 *      Board.cpp -- Board class file for Sudoku Lab
 * FUNCTIONAL DESCRIPTION:
 *      This program in C++ fulfills the requirements of the Sudoku Lab in 
 *      CSCI2101 Fall 2014.
 * 
 *      This source file contains the constructor and functions or methods for 
 *      the Board class.  The constructor creates and initializes a Board 
 *      object.  The printPuzzle method prints out the Sudoku board.  The 
 *      getValue function returns the value at a specified board index.  The 
 *      setValue function changes the value at a specified index.  The success
 *      function checks the entire board to see if it has been correctly filled
 *      in.  The legalMove function checks a specified Move to see if it is 
 *      valid and to make sure that it doesn't conflict with other values on the
 *      board.  The nextMove function finds the next legal Move on the Board and
 *      returns it, or returns an empty Move if no legal Moves are available. 
 *      
 * NOTICE:
 *      Copyright (C) 2014 Christopher MacDonald    All rights reserved.
 * 
 *===========================================================================
 */

#include "Board.h"
#include "Move.h"

/*
 * FUNCTION NAME: 
 *      Board (Constructor) -- creates and initializes a Board object
 * FUNCTIONAL DESCRIPTION:
 *      This function creates and initalizes a Board object.  A Board object is 
 *      a Sudoku puzzle, or a grid of numbers and empty spaces.  The constructor
 *      reads in a Sudoku puzzle text file.  If the text file is rectangular, 
 *      the constructor reads it in and sorts it into an array.  If the puzzle
 *      is not rectangular, the constructor will not create the array.     
 * ENTRY PARAMETERS:
 *      None.
 * RETURN VALUES: 
 *      None.
 */

Board::Board() {
    
    //
    //Declaration of variables
    //
    string fileName;
    string line;
    ifstream puzzleStream;
    
    //
    //Input the file name and make sure the file opens
    //
    do{
        cout << "Enter puzzle file name: ";
        cin >> fileName;
        puzzleStream.open(fileName, ios::in);
    } while (!puzzleStream.good());
        
    //
    //Make sure the file has some stuff in it
    //
    if (!getline(puzzleStream, line)){
        cerr << "Error: puzzle file is empty" << endl;
        numRows = 0;
        numCols = 0;
        return;
    }
    
    //
    //Put the first puzzle line in theBoard
    //
    numCols = line.size();
    for (int i = 0; i < numCols; i++){
        theBoard[0][i] = (line.at(i))-CHAR_CONVERTER;
    }
    
    //
    //Puts the rest of the puzzle lines in theBoard
    //
    for(numRows = 1; getline(puzzleStream, line); numRows++){
        
        //
        //Makes sure puzzle is rectangular
        //
        if(line.size() != numCols){
            cerr << "Error: puzzle is not rectangular" << endl;
            numRows = 0;
            numCols = 0;
            return;
        }
        
        //
        //Put this puzzle line in theBoard
        //
        for(int i = 0; i < numCols; i++){
            theBoard[numRows][i] = (line.at(i))-CHAR_CONVERTER;
        }
    } 
    cout << "The puzzle's dimensions are " << numRows << " rows by " << numCols
            << " columns." << endl; 
}

/*
 * FUNCTION NAME: 
 *      printPuzzle -- prints the puzzle in the output window
 * FUNCTIONAL DESCRIPTION:
 *      This function prints the puzzle with all digits 1-9 and underscores in 
 *      the output window. It prints the puzzle out in grid form with an equal 
 *      number of characters in each row and column. Each underscore represents 
 *      a zero.  
 * ENTRY PARAMETERS:
 *      None.
 * RETURN VALUES: 
 *      None.
 */

void Board::printPuzzle(){       
    //
    //if puzzle is empty, prints message saying so
    //
    if(numRows==0||numCols==0){
        cout<<"There is nothing in the puzzle!"<<endl<<endl;
        return;
    }
    //
    //Prints out each character of puzzle at each index with space in between
    //characters
    //
    for (int i=0; i<numRows;i++){    
        cout << endl;
        for (int j=0; j<numCols; j++){
            theBoard[i][j]= (theBoard[i][j]);
            if(theBoard[i][j]==0){
                cout<<" _";
            }
            else{
                cout << " " << theBoard[i][j];
            }    
        }
    }
    cout << endl<<endl;
}

/*
 * FUNCTION NAME: 
 *      getValue -- gets the value at a specified board index
 * FUNCTIONAL DESCRIPTION:
 *      This function returns the value contained at a specified index on the 
 *      board. 
 * ENTRY PARAMETERS:
 *      int row -- a row index
 *      int col -- a column index
 * RETURN VALUES: 
 *      int -- the number contained at the specified board index
 */
int Board::getValue(int row, int col){   
    return theBoard[row][col];
}

/*
 * FUNCTION NAME: 
 *      setValue -- changes the value at a board index
 * FUNCTIONAL DESCRIPTION:
 *      This function sets the value contained at a specified board index.   
 * ENTRY PARAMETERS:
 *      int row -- a row index
 *      int col -- a column index
 *      int value -- a number to be placed at the row-column index
 * RETURN VALUES: 
 *      None.
 */
void Board::setValue(int row, int col, int value){   
    theBoard[row][col]=value;
    return;
}

/*
 * FUNCTION NAME: 
 *      success -- checks to see if the puzzle has been successfully completed
 * FUNCTIONAL DESCRIPTION:
 *      This function check the entire puzzle to make sure it has been 
 *      successfully completed.  It makes sure no number has been repeated in 
 *      any row, column, or sub-square.  
 * ENTRY PARAMETERS:
 *      None.
 * RETURN VALUES: 
 *      bool -- returns TRUE if the board has been successfully completed, or 
 *              FALSE otherwise
 */
bool Board::success(){
    
    //declaration of variables
    int rowTemp;
    int colTemp;
    int subSquareTemp;
    int rowCount=0;
    int colCount=0;
    int subSquareCount;
    
    //check the rows and columns to make sure there are no empty spaces, then
    //checks the rows for repeats
    for(int r=0;r<numRows;r++){
        for(int c=0;c<numCols;c++){
            if(theBoard[r][c]==0){
                return 0;
            }
            //saves the value at the array index to temp, then uses the for loop
            //to check other values in the same row.  Count keeps track of the
            //number of times that value occurs
            rowCount=0;
            rowTemp=theBoard[r][c];
            for(int d=0;d<9;++d){
                if(rowTemp==theBoard[r][d]){
                    rowCount++;
                }
            }
            //if a digit appears in a row more than once, function is false
            if(rowCount>1){

                return 0;
            }
        }
    }
    
    //check the columns for repeats
    for(int r=0;r<numRows;r++){
        for(int c=0;c<numCols;c++){
            
            //saves the value at the array index to temp, then uses the for loop
            //to check other values in the same row.  Count keeps track of the
            //number of times that value occurs
            colCount=0;
            colTemp=theBoard[r][c];
            for(int d=0;d<9;++d){
                if(colTemp==theBoard[d][c]){
                    colCount++;
                }
            }
            //if a digit appears in a column more than once, function is false
            if(colCount>1){
                return 0;
            }
        }
    }
    
    //check all of the sub-squares
    for(int i=0;i<NUM_SUB_SQUARES; ++i){
        //choose a row and column to find the value, then compare that value to
        //other values in the sub-square
        for(int j=0; j<SUB_SQUARE_SIZE;j++){
            for(int k=0;k<SUB_SQUARE_SIZE;k++){
                subSquareTemp=theBoard[j+(i/3)*3][k+(i%3)*3];
                subSquareCount=0;
                
                //loop through rows and columns in the current sub-square to 
                //compare to the value of temp
                for(int m=0;m<SUB_SQUARE_SIZE;m++){
                    for(int n=0;n<SUB_SQUARE_SIZE;n++){
                        if(theBoard[m+(i/3)*3][n+(i%3)*3]==subSquareTemp){
                            subSquareCount++;
                        }
                        //if value is already in sub-square, function is false
                        if(subSquareCount>1){
                            return 0;
                        }
                    }
                }                
            }
        }
    }
    //If all checks pass, puzzle is successfully solved
    cout<<"The puzzle was successfully solved!\n";
    return 1;
}

/*
 * FUNCTION NAME: 
 *      legalMove -- finds the next legal Move on the board if there is one
 * FUNCTIONAL DESCRIPTION:
 *      This function    
 * ENTRY PARAMETERS:
 *      None.
 * RETURN VALUES: 
 *      None.
 */
bool Board::legalMove(Move move){
    
    //declaration of variables
    int temp;
    int count;
    
    //makes sure the inputted digit is between 1 and 9
    if(move.getDigit()<1||move.getDigit()>9){
        return 0;
    }
    
    //Check to see if the digit entry inputted through the move is already in 
    //the given column
    for(int r=0;r<numRows;r++){
        if(theBoard[r][move.getColumn()]==move.getDigit()){
            return 0;
        }
    }
    
    //Check to see if the digit entry inputted though the move is already in 
    //the given row
    for(int c=0;c<numCols;c++){
        if(theBoard[move.getRow()][c]==move.getDigit()){
            return 0;
        }
    }
    

    //Checks to make sure the number is not already in the subsquare
    count=0;
    for(int j=0;j<SUB_SQUARE_SIZE;j++){
        for(int k=0;k<SUB_SQUARE_SIZE;k++){
            temp=theBoard[j+(move.getRow()/3)*3][k+(move.getColumn()/3)*3];
            if(move.getDigit()==temp){
                count++;
            }
            if(count>=1){
                return 0;
            }
        }
    }
    
    //If the digit entry is not already in that row, column, or sub-square
    //the move is legal
    return 1;
}

/*
 * FUNCTION NAME: 
 *      nextMove -- finds the next legal move available in the puzzle
 * FUNCTIONAL DESCRIPTION:
 *      This function cycles through the board and finds the first empty index. 
 *      It then checks to see if there is a possible legal move at that index.
 *      If so, it returns that move, but if not it returns an empty move.  
 *      Also if the board is full then there is no possible next move so the 
 *      function also returns an empty move.   
 * ENTRY PARAMETERS:
 *      None.
 * RETURN VALUES: 
 *      Move -- the next legal move on the board, or an empty move
 */

Move Board::nextMove(){
    //cycles through the board array starting from top left looking for first
    //empty index
    for(int r=0;r<MAX_ROWS;r++){
        for(int c=0;c<MAX_COLS;c++){
            if(theBoard[r][c]==0){
                //checks to see if any of digits 1-9 is a legal move at the 
                //current index
                for(int d=1;d<=MAX_ROWS;d++){
                    Move next(r,c,d);
                    if(legalMove(next)){
                        return next;
                    }                    
                }
                //if none of the digits 1-9 are legal moves at the current empty
                //index, the last move must be revised and an empty next move is
                //returned
                return Move(r,c,0);
            } 
        }
    }
    //Returns an empty move if the board is full 
    cout<<"Board is full, no next move available!\n";
    return Move(0,0,0);
}


