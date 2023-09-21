//Arjun Vinsel
//21/SEP/2023
//This program is a text based version of the game tic tac toe. Players can win tie and play more than once

#include<iostream>
#include<cstring>

using namespace std;

void printBoard(char board[3][3]);
void clearBoard(char board[3][3]);
bool checkWin(int player, char board[3][3]);
bool checkTie(char board[3][3]);

const int X_MOVE = 1;
const int X_TURN = 1;
const int O_MOVE = 2;
const int O_TURN = 2;
const int NO_MOVE = 0;

int main () {
  char board[3][3];
  int oWins = 0;
  int xWins = 0;
  int numTies = 0;
  bool stillPlaying = true;
  char playAgain = ' ';
  clearBoard(board);
  int turn = X_TURN;
  while(stillPlaying == true) {
    while (checkWin(X_MOVE, board) == false && checkWin(O_MOVE, board) == false && checkTie(board) == false) {
    printBoard(board);
    char move[2];
    cin >> move;
    if (move[0] != 'a' && move[0] != 'b' && move[0] != 'c') {// Tests if first charecter in move is valid a, b, or c
      cout << "please enter a a, b, or c" << endl;
    }
    else if (move[1] != '1' && move[1] != '2' && move[1] != '3') {// Tests if second charecter is valid 1, 2, or 3
      cout << "please enter 1, 2, or 3" << endl;
    }
    else {// What happens when a move is valid
    int row = move[0] - 'a';
    int column = move[1] - '1';
    if (turn == X_TURN && board[row][column] == NO_MOVE) {// If the turn is valid and it is x's turn
        board[row][column] = X_MOVE;
        turn = O_TURN;
      }
    else if(turn == O_TURN && board[row][column] == NO_MOVE) {//If the turn is valid and it is o's turn
        board[row][column] = O_MOVE;
        turn = X_TURN;
      }
    else {// If there is already a piece there this code will tell the user to enter a new move
	cout << "There is a peice there please enter a new move" << endl;
      }
  }
  }
    if(checkWin(X_MOVE, board) == true) {// Checks to see if X has won if so prints out the win and the number of x wins o wins and ties
    xWins++;
    cout << "Winner is player X" << endl;
    cout << "Owins = " << oWins <<endl;
    cout << "Xwins = " << xWins <<endl;
    cout << "Ties = " << numTies <<endl;
  }
    else if(checkWin(O_MOVE, board) == true) {// Checks to see if o has won if so then prints out the win and the number of x wins o wins and ties
    oWins++;
    cout << "Winner is player O" << endl;
    cout << "Owins = " << oWins <<endl;
    cout << "Xwins = " << xWins <<endl;
    cout << "Ties = " << numTies <<endl;
  }
    else if(checkTie(board) == true) {// Checks to see if players are tied if so prints out number of ties o wins and x wins
    numTies ++;
    cout << "its a tie" << endl;
    cout << "Owins = " << oWins <<endl;
    cout << "Xwins = " << xWins <<endl;
    cout << "Ties = " << numTies <<endl;
  }
  cout << "want to play again, enter y or n" << endl;
  cin >> playAgain;
  if ( playAgain == 'y') {// if a person wants to play again it will set stillplaying too true reset the baord and set turn to x turn
      clearBoard(board);
      turn = X_TURN;
      stillPlaying = true;
    }
  else  {// Stops the game
      stillPlaying = false;
    }
  }

  return 0;
}


void printBoard(char board[3][3]) {//Prints board
  cout << "   1 2 3 " << endl;
  for(int row = 0; row < 3; row++) {
    char output [3];
    cout << (char)('a' + row);
    for(int column = 0; column < 3; column++) {
      if (board[row][column] == NO_MOVE) {
        cout<< " - ";
      }
      else if(board[row][column] == X_MOVE) {
        cout << " X ";
      }
      else if (board[row][column] == O_MOVE) {
        cout << " O ";
      }
    }
    cout << endl;
}
}

void clearBoard(char board[3][3]) {//Clears the board
  for(int row=0; row < 3; row ++) {
    for(int column=0; column < 3; column++) {
      board[row][column] = NO_MOVE;
    }
  }
}

bool checkWin(int player, char board[3][3]) { // checks if there are any wins on the board
  if (board[0][0] == player && board[0][1] == player && board[0][2] == player) { // Rows 1
    return true;
  }

  if (board[0][0] == player && board[1][1] == player && board[2][2] == player) { // Diagonal
    return true;
  }
  if (board[1][0] == player && board[1][1] == player && board[1][2] == player) { // Rows 2
    return true;
  }
  if (board[2][0] == player && board[2][1] == player && board[2][2] == player) { // Rows 3
    return true;
  }
  if (board[2][0] == player && board[1][1] == player && board[0][2] == player) { // Diagonal
    return true;
  }
  if (board[0][0] == player && board[1][0] == player && board[2][0] == player) { // Colum 1
    return true;
  }
  if (board[0][1] == player && board[1][1] == player && board[2][1] == player) { // colum 2
    return true;
  }
  if (board[0][2] == player && board[1][2] == player && board[2][2] == player) { // colum 3
    return true;
  }
 return false;
}

bool checkTie(char board[3][3]) { // checks if the players have tied
  for (int row = 0; row < 3; row++) {
    for (int column = 0; column < 3; column++) {
      if (board[row][column] == NO_MOVE) {
	return false;
      }
    }
  }
  return true;
}
