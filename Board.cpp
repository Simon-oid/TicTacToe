/// \file Board.cpp
/// \brief Implementation of the Board class methods


#include "Board.h"
#include <iostream>
#include <vector>

/// \brief Constructor: Initializes the game board with empty spaces
Board::Board() {
    for (int i = 0; i < SIZE; ++i) {
        for (int j = 0; j < SIZE; ++j) {
            grid[i][j] = ' ';
        }
    }
}


/// \brief Displays the current state of the board
void Board::display() {
    std::cout << "  0 1 2" << std::endl;
    for (int i = 0; i < SIZE; ++i) {
        std::cout << i << " ";
        for (int j = 0; j < SIZE; ++j) {
            std::cout << grid[i][j];
            if (j < SIZE - 1) std::cout << "|";
        }
        std::cout << std::endl;
        if (i < SIZE - 1) std::cout << "  -+-+-" << std::endl;
    }
}

/// \brief Makes a move on the board
/// \param row Row index for the move
/// \param col Column index for the move
/// \param player Current player making the move ('X' or 'O')
/// \return True if the move is valid, false otherwise
bool Board::makeMove(int row, int col, char player) {
    if (row < 0 || row >= SIZE || col < 0 || col >= SIZE || grid[row][col] != ' ')
        return false;
    grid[row][col] = player;
    return true;
}
/// \brief Checks if a player has won
/// \param player The player to check for a win
/// \return True if the player has won, false otherwise
bool Board::checkWin(char player) {
    for (int i = 0; i < 3; ++i)
        if (grid[i][0] == player && grid[i][1] == player && grid[i][2] == player)
            return true;

    for (int j = 0; j < 3; ++j)
        if (grid[0][j] == player && grid[1][j] == player && grid[2][j] == player)
            return true;

    if (grid[0][0] == player && grid[1][1] == player && grid[2][2] == player)
        return true;

    if (grid[0][2] == player && grid[1][1] == player && grid[2][0] == player)
        return true;

    return false;
}

/// \brief Checks if the game is a draw
/// \return True if the game is a draw, false otherwise
bool Board::checkDraw() {
    for (int i = 0; i < SIZE; ++i) {
        for (int j = 0; j < SIZE; ++j) {
            if (grid[i][j] == ' ') {
                return false;
            }
        }
    }
    return true;
}

/// \brief Gets the available moves on the board
/// \return A vector of available moves as pairs of row and column indices
std::vector<std::pair<int, int>> Board::getAvailableMoves() {
    std::vector<std::pair<int, int>> availableMoves;
    for (int i = 0; i < 3; ++i)
        for (int j = 0; j < 3; ++j)
            if (grid[i][j] == ' ')
                availableMoves.emplace_back(i, j);
    return availableMoves;
}


/// \brief Getter for the board array
/// \return The 2D array representing the board
const char(&Board::getBoard() const)[3][3]{
    return grid;
}