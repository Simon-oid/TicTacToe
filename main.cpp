/// \file main.cpp
/// \brief Entry point for the Tic Tac Toe game

#include <iostream>
#include "Game.h"

/// \brief Main function to start the Tic Tac Toe game
/// \return Exit status code
int main() {

	// Create game object
	Game game;

	// Start the game 
	game.play();

	return 0;
}