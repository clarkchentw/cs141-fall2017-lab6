// TicTacToe.cpp   for CS 141 lab 6
//
// Instructions: Change the program below so that it no longer
// uses global variables to represent the board, but rather:
//    1. Declares the board in main() as a 9 character array
//    2. Passes the board to a supplied displayBoard() function
//    3. Change the code so that it uses the array to make moves and check for a win,
//       appropriately doing this using functions.
//
// You get one point each for:
//    1. Getting displayBoard() to work
//    2. Allowing making moves
//    3. [extra credit] detecting and displaying a message when there is a win,
//       which is three of a player's pieces in a row, column or diagonal.

#include <iostream>
using namespace std;

char p0,p1,p2,p3,p4,p5,p6,p7,p8;


//---------------------------------------------------------------------
// You will need to comment out this old version once you change your program.
void displayBoard()
{
    cout << endl
    << "------- \n"
    << "|" << p0 << "|" << p1 << "|" << p2 << "|   1  2  3\n"
    << "------- \n"
    << "|" << p3 << "|" << p4 << "|" << p5 << "|   4  5  6\n"
    << "------- \n"
    << "|" << p6 << "|" << p7 << "|" << p8 << "|   7  8  9\n"
    << "------- "
    << endl;
}


//---------------------------------------------------------------------
// Your new program version should use the following
void displayBoard( char board[])
{
    cout << endl
    << "------- \n"
    << "|" << board[0] << "|" << board[1] << "|" << board[2] << "|   1  2  3\n"
    << "------- \n"
    << "|" << board[3] << "|" << board[4] << "|" << board[5] << "|   4  5  6\n"
    << "------- \n"
    << "|" << board[6] << "|" << board[7] << "|" << board[8] << "|   7  8  9\n"
    << "------- "
    << endl;
}


//---------------------------------------------------------------------
int main()
{
    // Initialize the board
    //*** Hint Initialize the board as a 1D array
    p0=p1=p2=p3=p4=p5=p6=p7=p8=' ';
    char pieceToMove = 'X';
    int position = 0;
    int moveNumber = 1;
    
    cout << "Welcome to the TicTacToe game! " << endl
    << "Take turns entering the position (1..9)" << endl
    << "into which your piece will be placed. "
    << endl
    << endl;
    // *** Hint call the new version of display board
    displayBoard();
    
    // Main loop
    while( true) {
        // Prompt for and get move.  Leave this here in your new version.
        cout << moveNumber << ". Enter the move (1..9) for " << pieceToMove << ": ";
        cin >> position;
        
        // Make move.  Note that while the board positions are labelled 1..9,
        // the board variables are numbered p0..p8, which is off by one.
        // *** Hint: This whole section of code should change in your new version
        switch (position) {
            case 1: p0 = pieceToMove; break;
            case 2: p1 = pieceToMove; break;
            case 3: p2 = pieceToMove; break;
            case 4: p3 = pieceToMove; break;
            case 5: p4 = pieceToMove; break;
            case 6: p5 = pieceToMove; break;
            case 7: p6 = pieceToMove; break;
            case 8: p7 = pieceToMove; break;
            case 9: p8 = pieceToMove; break;
        }
        
        // Check for win using board positions:
        //    0 1 2
        //    3 4 5
        //    6 7 8
        // *** Hints: 1. This whole section should be a function call in your new version.
        //            2. Furthermore each line below should itself be a function call
        //               to see if three characters are the same.
        if( (p0==p1 && p1==p2 && p2!=' ') ||  // top row
            (p3==p4 && p4==p5 && p5!=' ') ||  // middle row
            (p6==p7 && p7==p8 && p8!=' ') ||  // bottom row
            (p0==p3 && p3==p6 && p6!=' ') ||  // left column
            (p1==p4 && p4==p7 && p7!=' ') ||  // middle column
            (p2==p5 && p5==p8 && p8!=' ') ||  // right column
            (p0==p4 && p4==p8 && p8!=' ') ||  // upper-left to lower-right diagonal
            (p6==p4 && p4==p2 && p2!=' ')     // lower-left to upper-right diagonal
           ) {
            displayBoard();
            cout << endl
            << "Congratulations player " << pieceToMove << ". You WON!" << endl;
            break;
        }
        
        // Change to other piece for next move.  Leave this here in your new version.
        if( pieceToMove == 'X') {
            pieceToMove = 'O';
        }
        else {
            pieceToMove = 'X';
        }
        
        // *** Hint call the new version of display board
        displayBoard();
        
        moveNumber++;   // Increment the move number.
    }// End while
    
    cout << "Exiting program..." << endl;
    return 0;
}//  End Main
