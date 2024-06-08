/// \file Game.h
/// \brief Declaration of the Game class that manages the Tic Tac Toe game


#ifndef GAME_H
#define GAME_H

#include "Board.h"

/// \enum GameMode
/// \brief Represents the game modes
enum GameMode {
    PLAYER_VS_PLAYER,
    PLAYER_VS_AI
};


/// \class Game
/// \brief Manages the overall Tic Tac Toe game
class Game {
public:
    /// \brief Constructor: Initializes the game state
    Game();


    /// \brief Starts and plays the game
    void play();

private:

    char currentPlayer; ///< The current player ('X' or 'O')
    Board board; ///< The game board
    GameMode gameMode; ///< The game mode

    /// \brief Switches the current player
    void switchPlayer();

    /// \brief Handles the player move
    void playerMove();

    /// \brief Handles the AI move
    void aiMove();

    /// \brief Checks if the current player has won
    /// \return True if the current player has won, false otherwise
    bool checkWin();

    /// \brief Checks if the current player has won
    /// \return True if the current player has won, false otherwise
    bool checkDraw();

    /// \brief Selects the game mode
    void selectGameMode();

    
};

#endif // GAME_H
