/// \file Board.h
/// \brief Declaration of the Board class that manages the Tic Tac Toe board

#ifndef BOARD_H
#define BOARD_H

#include <vector>
#include <iostream>


/// \class Board
/// \brief Manages the Tic Tac Toe board
class Board {
public:

	/// \brief Constructor: Initializes the game board
	Board();

	/// \brief Displays the current state of the board
	void display();

	/// \brief Makes a move on the board
	/// \param row Row index for the move
	/// \param col Column index for the move
	/// \param player Current player making the move ('X' or 'O')
	/// \return True if the move is valid, false otherwise
	bool makeMove(int row, int col, char currentPlayer);

	/// \brief Checks if a player has won
	/// \param player The player to check for a win
	/// \return True if the player has won, false otherwise
	bool checkWin(char currentPlayer);

	/// \brief Checks if the game is a draw
	/// \return True if the game is a draw, false otherwise
	bool checkDraw();

	/// \brief Gets the available moves on the board
	/// \return A vector of available moves as pairs of row and column indices
	std::vector<std::pair<int, int>> getAvailableMoves();

	/// \brief Getter for the board array
	/// \return The 2D array representing the board
	const char(&getBoard() const)[3][3]; // getter for the board array

private:
	static const int SIZE = 3;  ///< The size of the board (3x3)
	char grid[SIZE][SIZE]; ///< 2D array to store the board state
};

#endif // BOARD_H
 