/// \file Game.cpp
/// \brief Implementation of the Game class methods

#include "Game.h"
#include "Board.h"
#include <iostream>
#include <cstdlib>
#include <ctime>
#include <vector>
#include <algorithm>


/// \brief Constructor: Initializes the current player to 'X' and creates a new Board object
Game::Game() : currentPlayer('X'), gameMode(PLAYER_VS_PLAYER) {
	std::srand(static_cast<unsigned int>(std::time(0)));
}

/// \brief Selects the game mode
/// \details The player can choose between Player vs Player and Player vs AI
void Game::selectGameMode() {
    int choice;
    std::cout << "Select Game Mode:\n";
    std::cout << "1. Player vs Player\n";
    std::cout << "2. Player vs AI\n";
    std::cout << "Enter choice (1 or 2): ";
    std::cin >> choice;
    if (choice == 1) {
        gameMode = PLAYER_VS_PLAYER;
    }
    else {
        gameMode = PLAYER_VS_AI;
    }
}

/// \brief Starts and plays the game
/// \details The game loop continues until a player wins or the game is a draw
void Game::play() {
    selectGameMode();
    while (true) {
        board.display();
        if (currentPlayer == 'X') {
            playerMove();
        }
        else {
            if (gameMode == PLAYER_VS_AI) {
                aiMove();
            }
            else {
                playerMove();
            }
        }
        if (checkWin()) {
            board.display();
            std::cout << "Player " << currentPlayer << " wins!\n";
            break;
        }
        if (checkDraw()) {
            board.display();
            std::cout << "The game is a draw!\n";
            break;
        }
        switchPlayer();
    }
}

/// \brief Switches the current player
void Game::switchPlayer() {
	currentPlayer = (currentPlayer == 'X') ? 'O' : 'X';
}

/// \brief Handles the player move
/// \details The player is prompted to enter the row and column for their move
void Game::playerMove() {
    int row, col;
    std::cout << "Player " << currentPlayer << ", enter your move (row and column): ";
    std::cin >> row >> col;
    while (row < 0 || row >= 3 || col < 0 || col >= 3 || !board.makeMove(row, col, currentPlayer)) {
        std::cout << "Invalid move. Try again: ";
        std::cin >> row >> col;
    }
}

/// \brief Handles the AI move
/// \details The AI makes a move based on the current board state
void Game::aiMove() {
    std::vector<std::pair<int, int>> moves = board.getAvailableMoves();
    const char(&grid)[3][3] = board.getBoard();

    // Check if X picked the center and all other cells are empty
    if (grid[1][1] == 'X' &&
        grid[0][0] == ' ' &&
        grid[0][1] == ' ' &&
        grid[0][2] == ' ' &&
        grid[1][0] == ' ' &&
        grid[1][2] == ' ' &&
        grid[2][0] == ' ' &&
        grid[2][1] == ' ' &&
        grid[2][2] == ' ') {

        // Choose a corner
        std::vector<std::pair<int, int>> corners = { {0, 0}, {0, 2}, {2, 0}, {2, 2} };
        int index = std::rand() % corners.size();
        board.makeMove(corners[index].first, corners[index].second, currentPlayer);
        return;
    }

    // Try to win
    for (auto move : moves) {
        Board tempBoard = board;
        tempBoard.makeMove(move.first, move.second, currentPlayer);
        if (tempBoard.checkWin(currentPlayer)) {
            board.makeMove(move.first, move.second, currentPlayer);
            return;
        }
    }

    // Try to block the player from winning
    char opponent = (currentPlayer == 'X') ? 'O' : 'X';
    for (auto move : moves) {
        Board tempBoard = board;
        tempBoard.makeMove(move.first, move.second, opponent);
        if (tempBoard.checkWin(opponent)) {
            board.makeMove(move.first, move.second, currentPlayer);
            return;
        }
    }

    // Make a random move
    int index = std::rand() % moves.size();
    board.makeMove(moves[index].first, moves[index].second, currentPlayer);
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