#ifndef __GAME_HPP__
#define __GAME_HPP__

// #include "game.hpp"
#include "ship.hpp"
#include "board.hpp"

// CONTROLLER

/**
 * @brief
 * Carrier      (C)        = 5 Hits
 * Battleship   (B)        = 4 Hits
 * Patrol       (P)        = 3 Hits
 * Submarine    (S)        = 3 Hits
 * Destroyer    (D)        = 2 Hits
 *
 * EMPTY        (?)
 * HIT          (!)
 * MISS         (~)
 */

class Game : Board, Ship {
    public:
        Game();
        ~Game();
        int hits;
        int misses;
        int playerSunk;
        int enemySunk;
        bool playerWins;
        bool enemyWins;
        
        void startGame();

        std::pair<int, int> getPlayerCoord();
        bool getPlayerVertical();

        bool setPlayerShip(char ch, bool v, std::pair<int, int> coord);

        void setEnemyBoard();

    private:
};

#endif