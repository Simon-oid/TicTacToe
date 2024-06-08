/// \file Game.cpp
/// \brief Implementation of the Game class methods

#include "Game.h"
#include "Board.h"
#include <iostream>


/// \brief Constructor: Initializes the current player to 'X' and creates a new Board object
Game::Game() : currentPlayer('X'), board() {}

/// \brief Starts and plays the game
void Game::play() {
	int row, col;
	bool gameEnded = false;

	// Main game loop
	while (!gameEnded) {

		// Display the board
		board.display();

		// Prompt the current player for their move
		std::cout << "Player " << currentPlayer << ", enter your move (row and column): ";
		std::cin >> row >> col;

		// Make the move if it's valid
		if (board.makeMove(row, col, currentPlayer)) {

			// Check if the current player has won
			if (checkWin()) {
				board.display();
				std::cout << "Player " << currentPlayer << " wins!" << std::endl;
				gameEnded = true;
			}
			// Check if the game is a draw
			else if (checkDraw()) {
				board.display();
				std::cout << "It's a draw!" << std::endl;
				gameEnded = true;
			}
			// Switch to the other player
			else {
				switchPlayer();
			}
		}
		// If the move is invalid, display an error message
		else {
			std::cout << "Invalid move. Try again." << std::endl;
		}
	}
}

/// \brief Switches the current player
void Game::switchPlayer() {
	currentPlayer = (currentPlayer == 'X') ? 'O' : 'X';
}

/// \brief Checks if the current player has won
/// \return True if the current player has won, false otherwise
bool Game::checkWin() {
	return board.checkWin(currentPlayer);
}

/// \brief Checks if the game is a draw
/// \return True if the game is a draw, false otherwise
bool Game::checkDraw() {
	return board.checkDraw();
}