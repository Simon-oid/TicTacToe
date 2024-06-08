/// \file Game.h
/// \brief Declaration of the Game class that manages the Tic Tac Toe game


#ifndef GAME_H
#define GAME_H

#include "Board.h"


/// \class Game
/// \brief Manages the overall Tic Tac Toe game
class Game {
public:
    /// \brief Constructor: Initializes the game state
    Game();


    /// \brief Starts and plays the game
    void play();

private:

    /// \brief Switches the current player
    void switchPlayer();

    /// \brief Checks if the current player has won
    /// \return True if the current player has won, false otherwise
    bool checkWin();

    /// \brief Checks if the current player has won
    /// \return True if the current player has won, false otherwise
    bool checkDraw();

    char currentPlayer; ///< The current player ('X' or 'O')
    Board board; ///< The game board
};

#endif // GAME_H
