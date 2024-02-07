// TASK 3

// Build a simple console-based Tic-Tac-Toe game that
// allows two players to play against each other
// TASK 3
// TIC-TAC-TOE GAME
// Game Board: Create a 3x3 grid as the game board.
// Players: Assign
// "X"
// and "O" to two players.
// Display Board: Show the current state of the board.
// Player Input: Prompt the current player to enter their move.
// Update Board: Update the game board with the player
// '
// s move.
// Check for Win: Check if the current player has won.
// Check for Draw: Determine if the game is a draw.
// Switch Players: Alternate turns between
// "X"
// and "O"
// players.
// Display Result: Show the result of the game (win, draw, or ongoing).
// Play Again: Ask if the players want to play another game
#include <iostream>
#include <vector>

using namespace std;

// Function declarations
void displayBoard(const vector<vector<char>>& board);
bool isMoveValid(const vector<vector<char>>& board, int row, int col);
bool checkForWin(const vector<vector<char>>& board, char player);
bool checkForDraw(const vector<vector<char>>& board);
bool playAgain();

int main() {
    char currentPlayer = 'X';
    vector<vector<char>> board(3, vector<char>(3, ' '));

    do {
        // Display the current state of the board
        displayBoard(board);

        // Player input
        int row, col;
        cout << "Player " << currentPlayer << ", enter your move (row and column): ";
        cin >> row >> col;

        // Check if the move is valid
        while (!isMoveValid(board, row, col)) {
            cout << "Invalid move! Please try again: ";
            cin >> row >> col;
        }

        // Update the board with the player's move
        board[row - 1][col - 1] = currentPlayer;

        // Check for a win
        if (checkForWin(board, currentPlayer)) {
            displayBoard(board);
            cout << "Player " << currentPlayer << " wins! Congratulations!\n";
            if (!playAgain()) {
                break;
            } else {
                // Reset the game board
                board = vector<vector<char>>(3, vector<char>(3, ' '));
                currentPlayer = 'X';
                continue;
            }
        }

        // Check for a draw
        if (checkForDraw(board)) {
            displayBoard(board);
            cout << "It's a draw! The game is over.\n";
            if (!playAgain()) {
                break;
            } else {
                // Reset the game board
                board = vector<vector<char>>(3, vector<char>(3, ' '));
                currentPlayer = 'X';
                continue;
            }
        }

        // Switch players for the next turn
        currentPlayer = (currentPlayer == 'X') ? 'O' : 'X';

    } while (true);

    cout << "Thank you for playing Tic-Tac-Toe! Goodbye!\n";

    return 0;
}

// Function to display the Tic-Tac-Toe board
void displayBoard(const vector<vector<char>>& board) {
    cout << "Tic-Tac-Toe Board:\n";
    for (int i = 0; i < 3; ++i) {
        for (int j = 0; j < 3; ++j) {
            cout << board[i][j];
            if (j < 2) {
                cout << " | ";
            }
        }
        cout << endl;
        if (i < 2) {
            cout << "---------\n";
        }
    }
    cout << endl;
}

// Function to check if a move is valid
bool isMoveValid(const vector<vector<char>>& board, int row, int col) {
    return (row >= 1 && row <= 3 && col >= 1 && col <= 3 && board[row - 1][col - 1] == ' ');
}

// Function to check for a win
bool checkForWin(const vector<vector<char>>& board, char player) {
    for (int i = 0; i < 3; ++i) {
        // Check rows and columns
        if ((board[i][0] == player && board[i][1] == player && board[i][2] == player) ||
            (board[0][i] == player && board[1][i] == player && board[2][i] == player)) {
            return true;
        }
    }

    // Check diagonals
    if ((board[0][0] == player && board[1][1] == player && board[2][2] == player) ||
        (board[0][2] == player && board[1][1] == player && board[2][0] == player)) {
        return true;
    }

    return false;
}

// Function to check for a draw
bool checkForDraw(const vector<vector<char>>& board) {
    for (int i = 0; i < 3; ++i) {
        for (int j = 0; j < 3; ++j) {
            if (board[i][j] == ' ') {
                return false; // If there's an empty space, the game is not a draw yet
            }
        }
    }
    return true; // All spaces are filled, indicating a draw
}

// Function to ask if players want to play again
bool playAgain() {
    char playAgainChoice;
    cout << "Do you want to play again? (y/n): ";
    cin >> playAgainChoice;
    return (playAgainChoice == 'y' || playAgainChoice == 'Y');
}
