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


//---------------------------------------------------------------------
// displayBoard Function
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
// Check win
// return true if win, return false if not yet win
bool checkWin(char board[]){
    // check horizontal win
    for (int i = 0; i < 9; i+=3){
        if (board[i] == board[i+1] && board[i+1] == board[i+2] && board[i+2] != ' '){
            return true;
        }
    }
    
    // check verticle win
    for (int i = 0; i < 3; i++){
        if (board[i] == board[i+3] && board[i+3] == board[i+6] && board[i+6] != ' '){
            return true;
        }
    }
    // check cross win
    if (board[0] == board[4] && board[4] == board[8] && board[8] != ' '){
        return true;
    }
    if (board[2] == board[4] && board[4] == board[6] && board[6] != ' '){
        return true;
    }
    
    return false;
}

//---------------------------------------------------------------------
// Check tie
// Return true if tie, return false if not yet tie
bool checkTie(char board[]){
    int emptySpot = 0;
    for (int i = 0; i < 9; i++){
        if (board[i] == ' '){
            emptySpot++;
        }
    }
    if (emptySpot == 0){
        return true;
    }
    else{
        return false;
    }
}


//---------------------------------------------------------------------
int main()
{
    
    // Initialize the board
    char boardData[9];
    for (int i = 0; i<9; i++){
        boardData[i] = ' ';
    }
    char pieceToMove = 'X';
    int position = 0;
    int moveNumber = 1;
    
    cout << "Welcome to the TicTacToe game! " << endl
    << "Take turns entering the position (1..9)" << endl
    << "into which your piece will be placed. "
    << endl
    << endl;
    
    displayBoard(boardData);
    
    // Main loop
    while( true) {
        // Prompt for and get move.
        cout << moveNumber << ". Enter the move (1..9) for " << pieceToMove << ": ";
        cin >> position;
        
        // Make move.  Note that while the board positions are labelled 1..9,
        boardData[position-1] = pieceToMove;
        
        // Check for win:
        if(checkWin(boardData)) {
            displayBoard(boardData);
            cout << endl
            << "Congratulations player " << pieceToMove << ". You WON!" << endl;
            break;
        }
        
        // Check for tie:
        if(checkTie(boardData)) {
            displayBoard(boardData);
            cout << endl
            << "Tie!! So you don't have to fight!!" << endl;
            break;
        }
        
        // Change to other piece for next move.
        if( pieceToMove == 'X') {
            pieceToMove = 'O';
        }
        else {
            pieceToMove = 'X';
        }
        
        displayBoard(boardData);
        
        moveNumber++;   // Increment the move number.
    }// End while
    
    cout << "Exiting program..." << endl;
    return 0;
}//  End Main
